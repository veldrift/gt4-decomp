typedef int s32;
typedef float f32;
typedef unsigned char u8;
typedef signed char s8;

extern s8 D_00622088[];
extern u8 D_00622090[];
extern u8 D_00622098[];
extern s8 D_006220A0[];
extern s8 D_006220A8[];
extern f32 D_006220B0[];
extern f32 D_006220C8[];
extern f32 D_006220E0[];

extern "C" void func_003F1790(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        D_006220A8[i] = (s8)((((s32)D_00622088[i] << 7) + 0x3200) / 100);
        D_006220B0[i] = (f32)D_00622090[i] / 100.0f;
        D_006220C8[i] = (f32)D_00622098[i] / 100.0f;
        D_006220E0[i] = (f32)(D_006220A0[i] + 100) / 100.0f;
    }
}
