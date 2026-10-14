/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
extern "C" void func_00493C70(void *, void *, s32, s32, __builtin_va_list);
extern char D_00492ED0[];
struct Obj {
    char p0[0x30];
    s32 f30;
    char p34[0x44 - 0x34];
    s32 f44;
    char p48[0x68 - 0x48];
    s32 f68;
    char p6C[0x78 - 0x6C];
    s32 f78;
};
extern "C" f32 func_00490A98(struct Obj *self, s32 arg1, ...) {
    f32 r = 0.0f;
    __builtin_va_list args;
    if (self->f68 == 0) {
        __builtin_stdarg_start(args, arg1);
        s32 t = self->f44;
        self->f30 = 0;
        func_00493C70(self, D_00492ED0, 0, arg1, args);
        self->f44 = t;
        self->f78 = 0;
        r = *(f32 *)&self->f30;
    }
    return r;
}
