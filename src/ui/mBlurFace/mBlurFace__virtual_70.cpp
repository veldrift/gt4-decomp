typedef int s32;
typedef short s16;
typedef float f32;

struct C {
    char pad0[0xA0];
    s32 unkA0;
    f32 unkA4;
    f32 unkA8;
};

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, f32);
};

static inline void vcall(char *o, s32 off, s32 a1, f32 f) {
    VE *e = (VE *)(*(char **)(o + 4) + off);
    e->fn(o + e->delta, a1, f);
}

extern "C" void func_002638E0(void *, void *, s32);
extern "C" void func_0025BAA0(C *arg0, s32 a1, s32 a2, s32 a3, s32 a4);

extern "C" void func_0027C2D8(void *arg0, void *arg1, s32 arg2) {
    C *self = (C *)arg0;
    f32 v[4];

    func_002638E0(arg0, arg1, 0);
    if (arg2 != 0) {
        if (self->unkA0 != 0) {
            if (self->unkA4 > 0.0f) {
                v[0] = 0.0f;
                v[1] = 0.0f;
                v[2] = 0.0f;
                v[3] = 0.0f;
                func_0025BAA0(self, (s32)&v[0], (s32)&v[1], (s32)&v[2], (s32)&v[3]);
                {
                    VE *e = (VE *)(*(char **)((char *)arg1 + 4) + 0x220);
                    f32 f = 1.0f - self->unkA4;
                    e->fn((char *)arg1 + e->delta, (s32)&v[0], f);
                }
            }
        } else {
            f32 a4 = self->unkA4;
            f32 a8 = self->unkA8;
            if (a4 < a8) {
                self->unkA4 = a4 + 0x1.999998p-4f;
            } else {
                self->unkA4 = a8;
            }
            if (self->unkA4 > 0.0f) {
                vcall((char *)arg1, 0x218, 5, self->unkA4);
            }
        }
    }
}
