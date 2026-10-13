extern unsigned char D_0064C10C;
extern char D_0086B3F8[];
extern "C" int func_0053A878(char *);

extern "C" int func_0053A9F8(void) {
    if (D_0064C10C == 1) {
        return 0x640;
    }
    {
        int r = func_0053A878(D_0086B3F8);
        if (r == 0) {
            D_0064C10C = 1;
        }
        return r;
    }
}
