typedef unsigned char u8;

extern unsigned char D_00621FF8[];
extern float D_00845940[];
extern float D_00845958[];

extern "C" void func_003EFF28(void) {
    u8 *base = D_00621FF8;
    float *f0 = D_00845940;
    float *f1 = D_00845958;
    u8 *p = base + 0x20;
    int i;
    for (i = 0; i < 6; i++) {
        u8 a = p[-8];
        u8 b = p[0];
        p++;
        f0[i] = (float)(a * 10);
        f1[i] = (float)b;
    }
}
