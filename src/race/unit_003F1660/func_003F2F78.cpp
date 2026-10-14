/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" u8 D_00620CD8[];
extern "C" float D_00622308, D_0062230C, D_00622310, D_00622314, D_00622318;
extern "C" void func_003F2F78(void) {
    u8 a = D_00620CD8[0];
    float fa = a;
    D_00622308 = fa * 0x1.999998p-4f;
    if (a != 0) {
        D_0062230C = D_00620CD8[1] / fa;
        D_00622310 = D_00620CD8[2] / fa;
    } else {
        D_0062230C = 0.0f;
        D_00622310 = 0.0f;
    }
    if (D_00620CD8[5] != 0)
        D_00622314 = 10.0f / D_00620CD8[5];
    else
        D_00622314 = 1.0f;
    if (D_00620CD8[6] != 0)
        D_00622318 = 10.0f / D_00620CD8[6];
    else
        D_00622318 = 0.25f;
}
