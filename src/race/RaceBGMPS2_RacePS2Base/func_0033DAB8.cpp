typedef int s32;
extern int D_0062020C;
extern int D_008434F8[16];
extern "C" void func_004A13C8(void *);
extern "C" int func_005A5600(void);

extern "C" void func_0033DAB8(void) {
    int i, j, k, t;
    if (D_0062020C == 0) {
        for (int n = 0; n < 16; n++) D_008434F8[n] = (n + 1) / 2 - 4;
        for (j = 0; j < 20; j++) {
            for (i = 0; i < 16; i++) {
                int k2 = (int)((float)func_005A5600() * 4.6566129e-10f * 16.0f);
                int t2 = D_008434F8[i];
                D_008434F8[i] = D_008434F8[k2];
                D_008434F8[k2] = t2;
            }
        }
        D_0062020C = 1;
    }
    for (i = 0; i < 16; i++) {
        k = (int)((float)func_005A5600() * 4.6566129e-10f * 16.0f);
        t = D_008434F8[i];
        D_008434F8[i] = D_008434F8[k];
        D_008434F8[k] = t;
    }
    func_004A13C8(D_008434F8);
}
