struct Sub {
    char pad0[0x4B8];
    union {
        struct {
            unsigned short flags;
            unsigned short timer;
        } h;
        float fl;
    } u;
    char pad1[0x4CC - 0x4BC];
    float lim;
};

struct Obj {
    char pad0[0x54C];
    float k;
    char pad1[0x5D4 - 0x550];
    float cur;
};

extern unsigned char D_00620E25;

extern "C" void func_00354D60(Obj *self, float t) {
    Sub *s = (Sub *)((char *)self + 0x104);
    if (s->u.h.flags & 0x100) {
        float lim = s->lim;
        float *p = &self->cur;
        if (t == 0.0f)
            t = (float)D_00620E25 * 0x1.999998p-4f;
        float nv = *p + t * self->k;
        *p = nv;
        if (lim <= nv) {
            *p = lim;
            int v = s->u.h.flags ^ 0x100;
            s->u.h.flags = (unsigned short)v;
            if (!(v & 0xC0))
                s->u.h.timer = 0x5A;
        }
    }
}
