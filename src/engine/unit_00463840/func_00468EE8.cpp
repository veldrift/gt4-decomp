/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern "C" int func_00359A38(void *, int, void *, void *, void *, void *);
extern "C" void *func_005A48D8(void *, int, unsigned);
struct Dest { u8 pad[0x94]; float first[2]; u8 pad9c[0x28]; float second[2]; u8 padcc[0x2c]; float x[12],y[12]; };
struct Source { u8 pad[0x48]; u8 x[12],y[12]; };
extern "C" int func_00468EE8(u8 *arg0, u8 *arg1) {
    u8 *var_a3_2;
    u8 *var_v1;
    u8 temp_a1;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    int var_a2;
    u8 *temp_s0;
    u8 *temp_s1;
    u8 *var_a0;
    u8 *var_a3;

    func_005A48D8(arg0, 0, 0x164);
    *(u8 *)(arg0 + 0) = (u8) *(u8 *)(arg1 + 0);
    *(u8 *)(arg0 + 1) = (u8) *(u8 *)(arg1 + 1);
    *(u8 *)(arg0 + 2) = (u8) *(u8 *)(arg1 + 2);
    *(u8 *)(arg0 + 5) = 0U;
    *(f32 *)(arg0 + 0x78) = 0x0.0p+0f;
    *(f32 *)(arg0 + 0x7C) = 0x0.0p+0f;
    *(f32 *)(arg0 + 0x84) = 0x0.0p+0f;
    *(f32 *)(arg0 + 0x80) = 0x0.0p+0f;
    if (*(u8 *)(arg1 + 0x28) != 0) {
        *(u8 *)(arg0 + 5) = 1U;
        *(f32 *)(arg0 + 0x78) = (f32) ((f32) *(u8 *)(arg1 + 0x2B) * 0x1.9999980000000p-4f);
        *(f32 *)(arg0 + 0x7C) = (f32) ((f32) *(u8 *)(arg1 + 0x2C) * 0x1.9999980000000p-4f);
    }
    if (*(u8 *)(arg1 + 0x29) != 0) {
        *(u8 *)(arg0 + 5) = (u8) (*(u8 *)(arg0 + 5) | 2);
    }
    if (*(u8 *)(arg1 + 0x2A) != 0) {
        *(u8 *)(arg0 + 5) = (u8) (*(u8 *)(arg0 + 5) | 4);
    }
    if (*(u8 *)(arg0 + 5) != 0) {
        *(f32 *)(arg0 + 0x80) = (f32) ((f32) *(u8 *)(arg1 + 0x2D) * 0x1.9999980000000p-4f);
        *(f32 *)(arg0 + 0x84) = (f32) ((f32) *(u8 *)(arg1 + 0x2E) * 0x1.9999980000000p-4f);
    }
    if ((*(u8 *)(arg0 + 8) = *(u8 *)(arg1 + 0x30)) != 0) {
        *(f32 *)(arg0 + 0x88) = (f32) ((f32) *(u8 *)(arg1 + 0x31) * 0x1.47ae140000000p-7f);
        *(f32 *)(arg0 + 0x8C) = (f32) ((f32) *(u8 *)(arg1 + 0x32) * 0x1.47ae140000000p-7f);
    }
    *(u8 *)(arg0 + 9) = (u8) *(u8 *)(arg1 + 0x34);
    *(f32 *)(arg0 + 0x90) = (f32) ((f32) *(u8 *)(arg1 + 0x35) * 0x1.47ae140000000p-7f);
    *(u8 *)(arg0 + 4) = (u8) *(u8 *)(arg1 + 0x24);
    *(f32 *)(arg0 + 0x74) = (f32) ((f32) *(u8 *)(arg1 + 0x25) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x10) = (f32) *(u8 *)(arg1 + 9);
    *(f32 *)(arg0 + 0x14) = (f32) *(u8 *)(arg1 + 0xA);
    *(f32 *)(arg0 + 0x18) = (f32) ((f32) *(u8 *)(arg1 + 0xB) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x1C) = (f32) ((f32) *(u8 *)(arg1 + 0xC) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x20) = (f32) ((f32) *(u8 *)(arg1 + 0xD) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x24) = (f32) ((f32) *(u8 *)(arg1 + 0xE) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x2C) = (f32) ((f32) *(u8 *)(arg1 + 0x10) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x30) = (f32) ((f32) *(u8 *)(arg1 + 0x11) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x34) = (f32) ((f32) *(u8 *)(arg1 + 0x12) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x38) = (f32) ((f32) *(u8 *)(arg1 + 0x13) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x3C) = (f32) ((f32) *(u8 *)(arg1 + 0x14) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x40) = (f32) ((f32) *(u8 *)(arg1 + 0x15) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x44) = (f32) ((f32) *(u8 *)(arg1 + 0x16) * 0x1.9999980000000p-4f);
    *(f32 *)(arg0 + 0x5C) = (f32) ((f32) *(u8 *)(arg1 + 0x1C) * 0x1.47ae140000000p-7f);
    *(s8 *)(arg0 + 0xA) = 0;
    ((Dest *)arg0)->first[0] = (f32) ((f32) *(u8 *)(arg1 + 0x39) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0x98) = (f32) ((f32) *(u8 *)(arg1 + 0x3A) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0x9C) = (f32) (-(f32) *(u8 *)(arg1 + 0x3B) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xA0) = (f32) (-(f32) *(u8 *)(arg1 + 0x3C) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xA4) = (f32) ((f32) *(u8 *)(arg1 + 0x3D) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xA8) = (f32) ((f32) *(u8 *)(arg1 + 0x3E) / 0x1.9000000000000p+6f);
    func_00359A38(arg0 + 0xAC, 2U, arg0+0x94, arg0 + 0x9C, 0, 0);
    func_00359A38(arg0 + 0xB8, 2U, arg0+0x94, arg0 + 0xA4, 0, 0);
    *(s8 *)(arg0 + 0xB) = 0;
    ((Dest *)arg0)->second[0] = (f32) ((f32) *(u8 *)(arg1 + 0x40) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xC8) = (f32) ((f32) *(u8 *)(arg1 + 0x41) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xCC) = (f32) (-(f32) *(u8 *)(arg1 + 0x42) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xD0) = (f32) (-(f32) *(u8 *)(arg1 + 0x43) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xD4) = (f32) ((f32) *(u8 *)(arg1 + 0x44) / 0x1.9000000000000p+6f);
    *(f32 *)(arg0 + 0xD8) = (f32) ((f32) *(u8 *)(arg1 + 0x45) / 0x1.9000000000000p+6f);
    func_00359A38(arg0 + 0xDC, 2U, arg0+0xc4, arg0 + 0xCC, 0, 0);
    func_00359A38(arg0 + 0xE8, 2U, arg0+0xc4, arg0 + 0xD4, 0, 0);
    *(f32 *)(arg0 + 0xF4) = (f32) ((f32) *(u8 *)(arg1 + 0x46) / 0x1.9000000000000p+6f);
    temp_a1 = *(u8 *)(arg1 + 0x47);
    for(int i=0;i<temp_a1;i++) {
        ((Dest *)arg0)->x[i]=(float)((Source *)arg1)->x[i]/100.0f;
        ((Dest *)arg0)->y[i]=(float)((Source *)arg1)->y[i]/100.0f;
    }
    return func_00359A38(arg0 + 0x158, temp_a1, arg0 + 0xF8, arg0+0x128, 0, 0);
}
