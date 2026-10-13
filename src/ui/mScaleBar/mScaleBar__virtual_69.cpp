typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0xC4];
    f32 fC4;
    char pad1[0x8];
    f32 fD0;
    f32 fD4;
    char pad2[0x18];
    void *fF0;
    void *fF4;
    char pad3[0x8];
    s32 f100;
};

extern "C" {
s32 func_00238F58(Obj *);                           /* extern */
f32 func_0025B370(void *);                          /* extern */
f32 func_0025B3D0(void *);                          /* extern */
void func_0025B2E0(void *, f32);                    /* extern */
void func_0025B340(void *, f32);                    /* extern */
void func_002638D8(void *, s32, s32);               /* extern */
void *func_0057B0F8(void *, f32, f32);              /* extern */
}

extern "C" void func_00238828(Obj *arg0, s32 arg1) {
    f32 f20;
    f32 f21;
    f32 f1;
    f32 f3;
    f32 f2;
    f32 t;
    void *tgt;
    char *sub;

    func_002638D8(arg0, arg1, 0);
    if (arg0->fF4 != 0) {
        tgt = arg0;
        if (arg0->f100 != 0) {
            void *c = arg0->fF0;
            tgt = (c != 0) ? c : (void *)arg0;
        }
        if (func_00238F58(arg0) != 0) {
            f21 = func_0025B370(tgt);
        } else {
            f21 = func_0025B3D0(tgt);
        }
        if (func_00238F58(arg0) != 0) {
            f20 = func_0025B370(arg0->fF4);
        } else {
            f20 = func_0025B3D0(arg0->fF4);
        }
        sub = (char *)arg0 + 0xDC;
        func_0057B0F8(sub, arg0->fC4, 0x1.999998p-3f);
        f1 = arg0->fD4;
        f3 = arg0->fD0;
        f2 = f1 - f3;
        if (0.0f < f2) {
            t = ((*(f32 *)(sub + 8) - f3) / f2) * (f21 - f20);
            if (func_00238F58(arg0) != 0) {
                return func_0025B2E0(arg0->fF4, t);
            }
            func_0025B340(arg0->fF4, t);
        }
    }
}
