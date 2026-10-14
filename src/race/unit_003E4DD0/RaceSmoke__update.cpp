/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rec {
    union { struct { s32 link:13; u32 rest:19; } bits; struct { unsigned short low; unsigned char flags, type; } bytes; u32 word; } u;
    char pad4[4];
    float size, life, x10, angle, vel, x1c;
    float x20, height, x28, ground;
    char pad30[16];
};
struct Pool { Rec *recs; short head; unsigned short freehead; char pad8[0x30]; char *cfg; };
extern float D_006A3A80[];
extern "C" void RaceSmoke__update(Pool *p, float dt) {
    Rec *pref;
    s32 i = p->head;
    s32 prev = -1;
    if (i >= 0) {
        do {
            Rec *r = p->recs + i;
            s32 next = r->u.bits.link;
            if (next >= 0) {
                pref = p->recs + next;
                __asm__ volatile("pref 0x0, %0" : : "m"(pref));
            }
            s32 off = r->u.bytes.type * 0x44;
            s32 o1 = off + 0x4e0;
            float angle;
            float rot = *(float *)(p->cfg + o1 + 12);
            unsigned char flags = r->u.bytes.flags;
            if (!(flags & 0x20)) rot = -rot;
            float size = r->size;
            float denom = size;
            if (size < 1.0f) denom = 1.0f;
            float rate = D_006A3A80[flags & 7] / denom;
            float factor1 = (float)*(unsigned char *)((char *)r + 0x1e) * 0.0078125f;
            float factor2 = (float)*(unsigned short *)((char *)r + 0x1c) * 0.00390625f;
            float gravity = dt * 0x1.39eb84p+3f;
            s32 o2 = off + 0x4f0;
            float v_angle = r->angle;
            angle = v_angle;
            float life = r->life;
            float vel = r->vel;
            float height = r->height;
            rot *= rate;
            angle += rot * dt;
            r->angle = angle;
            r->size = size + *(float *)(p->cfg + o1 + 4) * dt * factor1;
            r->life = life - *(float *)(p->cfg + o2) * dt * factor2;
            vel -= gravity * *(float *)(p->cfg + o2 + 12);
            r->vel = vel;
            r->height = height + vel * dt;
            if (angle > 360.0f) r->angle = angle - 360.0f;
            if (r->angle < 0.0f) r->angle += 360.0f;
            s32 dead = r->life <= 0.0f;
            if (!dead) {
                if (r->height + r->size * 0x1.3504f2p+0f + 0.0f < r->ground) dead = 1;
            }
            if (dead) {
                if (prev >= 0) {
                    Rec *old = (Rec *)(prev * 64 + (s32)p->recs);
                    old->u.word = (old->u.word & ~0x1fffu) | (r->u.word & 0x1fff);
                } else p->head = r->u.bits.link;
                u32 freeidx = p->freehead;
                r->u.word = (r->u.word & ~0x1fffu) | (freeidx & 0x1fff);
                p->freehead = i;
            } else prev = i;
            i = next;
        } while (i >= 0);
    }
}
