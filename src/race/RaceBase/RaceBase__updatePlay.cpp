typedef int s32;
typedef short s16;
typedef float f32;

struct Sub {
    char pad0[0xD0];
    s32 cnt;
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad1[4];
    Sub *sub;
    char pad2[0xCC0];
    f32 f30;
    char pad3[0xC];
    f32 f40;
    s32 n44;
};

struct VA { s16 delta; s16 index; void (*fn)(void *, s32, f32, f32); };
struct VB { s16 delta; s16 index; s32 (*fn)(void *); };
struct VC { s16 delta; s16 index; void (*fn)(void *); };
struct VD { s16 delta; s16 index; f32 (*fn)(void *); };

extern "C" void RaceOrganization__raceRealTimeUpdate(char *arg0, f32 fparg0);

extern "C" void RaceBase__updatePlay(char *arg0, f32 fparg0) {
    Obj *self = (Obj *)arg0;
    Sub *s = self->sub;
    s32 i;
    s32 n;
    s32 flag;
    f32 r;
    f32 t;

    if (s->cnt != 0) {
        if ((s32)self->f30 >= s->cnt) {
            VA *e = (VA *)(self->vtbl + 0x2B8);
            e->fn((char *)self + e->delta, 3, 0.0f, 0.0f);
        }
    }

    VB *e8 = (VB *)(self->vtbl + 0x108);
    s32 v = e8->fn((char *)self + e8->delta);
    RaceOrganization__raceRealTimeUpdate((char *)s, fparg0 * (f32)v);

    self->n44 = 0;

    VB *e0 = (VB *)(self->vtbl + 0xF8);
    flag = e0->fn((char *)self + e0->delta);
    if (flag != 0) {
        i = 0;
        VD *ed = (VD *)(self->vtbl + 0x100);
        r = ed->fn((char *)self + ed->delta);
        t = self->f40 + r;
        n = (s32)t;
        self->f40 = t - (f32)n;
        if (n > 0) {
            do {
                self->n44 = i;
                i += 1;
                VC *e = (VC *)(self->vtbl + 0x258);
                e->fn((char *)self + e->delta);
            } while (i < n);
        }
        self->n44 = 0;
    } else {
        VC *e = (VC *)(self->vtbl + 0x258);
        e->fn((char *)self + e->delta);
    }

    VC *e2 = (VC *)(self->vtbl + 0x260);
    e2->fn((char *)self + e2->delta);
}
