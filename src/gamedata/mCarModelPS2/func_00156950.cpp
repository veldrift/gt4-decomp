/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

extern char D_0065B7E0[];

struct Local {
    void *vt;
    f32 w[21];
    ~Local() { vt = D_0065B7E0; }
};

struct Tgt {
    char pad0[0xC];
    f32 fC;
};

struct Obj {
    char pad0[0x188];
    s32 f188;
    char pad18C[0x1B0 - 0x18C];
    s32 f1B0;
    char pad1B4[0x2A4 - 0x1B4];
    char f2A4[0x864 - 0x2A4];
    char f864[0x870 - 0x864];
    Tgt *f870;
    char pad874[0x8A8 - 0x874];
    f32 f8A8;
};

extern "C" void func_00156820(s32) throw();
extern "C" void func_00156920(s32) throw();
extern "C" f32 func_00364B30(void *, s32);
extern "C" void func_00451A00(void *, void *, s32, s32, s32, s32, f32);
extern "C" void func_00459780(Local *, void *);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);

extern "C" void func_00156950(Obj *self, s32 arg1) {
    s32 *s5 = (s32 *)self->f2A4;
    if (*s5 != 0) {
        Local L;
        func_004A53F8();
        func_00156820(arg1);
        func_00459780(&L, self->f864);
        if (self->f8A8 > 0.0f) {
            L.w[19] = self->f8A8;
            s32 i = 0;
            f32 *dst = &L.w[5];
            for (; i < 4; i++) {
                f32 a = func_00364B30((self->f864), i);
                f32 v;
                if (self->f8A8 < a) {
                    v = -self->f8A8;
                } else {
                    v = -a;
                }
                *dst = v;
                dst += 4;
            }
        }
        f32 t = 0.0f;
        if (self->f870 != 0) {
            t = self->f870->fC;
        }
        L.w[20] = t;
        s32 flag = 0;
        if (self->f188 != 0) {
            flag = self->f1B0 != 0;
        }
        func_00451A00(s5, &L, 0, arg1 ^ 1, 0, flag, 0.0f);
        func_00156920(arg1);
        func_004A5400();
    }
}
