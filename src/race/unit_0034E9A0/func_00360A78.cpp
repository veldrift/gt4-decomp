extern unsigned char D_00620CD8[];
extern int D_00620CB0;
extern float D_00620CB8[];
extern float D_00620CC0[];
extern float D_00620CC8[];
extern float D_00620CD0[];
extern "C" void func_00360A78(void) {
    unsigned char *a;
    float *b1;
    float *b2;
    float *b3;
    float *b4;
    float f0;
    float f1;
    float f2;
    float f3;
    int i;
    float k;
    float h;
    D_00620CB0 = D_00620CD8[0x102] != 0;
    if (D_00620CB0 != 0) {
        b1 = D_00620CB8;
        b2 = D_00620CC0;
        b3 = D_00620CC8;
        b4 = D_00620CD0;
        a = D_00620CD8 + 0x10B;
        k = 0.01f;
        h = 100.0f;
        i = 0;
        do {
            f1 = (float)a[-6] * k;
            f3 = (float)a[-4] / h;
            f0 = (float)a[-2] * k;
            f2 = (float)a[0] / h;
            b1[i] = f1;
            b2[i] = f3;
            b3[i] = f0;
            b4[i] = f2;
            a = a + 1;
            i = i + 1;
        } while (i < 2);
    }
}
