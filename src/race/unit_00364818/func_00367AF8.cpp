/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct Dst {
    char pad0[0x30];
    f32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64;
    char pad68;
    u8 b69;
};

extern u8 D_00620B60;
extern s16 D_00620B62;
extern s16 D_00620B64;
extern s16 D_00620B66;
extern s16 D_00620B68;
extern s16 D_00620B6A;
extern s16 D_00620B6C;
extern s16 D_00620B6E;
extern s16 D_00620B70;
extern u8 D_00620B72;
extern u8 D_00620B73;
extern u8 D_00620B74;
extern u8 D_00620B75;
extern u8 D_00620B76;

extern "C" void func_00367AF8(Dst *d) {
    if (D_00620B60 != 0) {
        d->f30 = (f32)D_00620B62 * 0x1.0624dcp-10f;
        d->f34 = (f32)D_00620B64 * 0x1.0624dcp-10f;
        d->f38 = (f32)D_00620B66 * 0x1.0624dcp-10f;
        d->f3C = (f32)D_00620B68 * 0x1.0624dcp-10f;
        d->f40 = (f32)D_00620B6A * 0x1.0624dcp-10f;
        d->f44 = (f32)D_00620B6C * 0x1.0624dcp-10f;
        d->f48 = (f32)D_00620B6E * 0x1.0624dcp-10f;
        d->f4C = (f32)D_00620B70 * 0x1.0624dcp-10f * 0x1.abfd8p-14f;
        d->f50 = (f32)D_00620B72 * -0x1.47ae14p-7f;
        d->f54 = (f32)D_00620B73 * 0x1.47ae14p-7f;
        d->f58 = (f32)D_00620B74 * 0x1.47ae14p-7f;
        d->f5C = (f32)D_00620B75 * 0x1.47ae14p-7f;
        d->f60 = 1.0f;
        d->f64 = (f32)D_00620B76 * 0x1.47ae14p-7f;
        d->b69 = 1;
    }
}
