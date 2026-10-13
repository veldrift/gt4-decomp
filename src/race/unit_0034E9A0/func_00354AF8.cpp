typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

extern unsigned char D_00620E24;

extern "C" s32 func_00354AC0(char *a0);

extern "C" s32 func_00354AF8(char *arg0, char *arg1) {
    char *self = arg0;
    char *a3 = self + 0x104;
    u8 a2;
    s32 t;
    s32 v;
    f32 f1;
    f32 f0;
    f32 f2;

    *(u8 *)(a3 + 0x4BD) = 1;
    *(s32 *)(a3 + 0x4C0) = 0;
    *(s16 *)(a3 + 0x4BE) = 0;
    *(s32 *)(a3 + 0x4C4) = 0;
    *(s32 *)(a3 + 0x4C8) = 0;

    t = *(u8 *)(*(char **)(self + 0x10) + 0x104B);
    a2 = *(u8 *)(arg1 + 0x4C);
    v = (a2 == 0) ? 0 : t;

    f1 = (f32)v;
    *(f32 *)(a3 + 0x4D0) = f1;
    *(f32 *)(a3 + 0x4CC) = f1;

    if (v != 0) {
        f2 = *(f32 *)(a3 + 0x4C0);
        f0 = f1 - (f32)D_00620E24;
        *(f32 *)(a3 + 0x4D0) = f0;
        if (f0 < f2) {
            *(f32 *)(a3 + 0x4D0) = f2;
        }
    }

    return func_00354AC0(arg0);
}
