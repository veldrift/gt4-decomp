typedef int s32;

extern unsigned char D_0064C10C;
extern char D_0086B3F8[];
extern "C" s32 func_0053A878(char *);

extern "C" s32 func_0053AA48(void) {
    if (D_0064C10C == 0) {
        return 1;
    }
    s32 r = func_0053A878(D_0086B3F8);
    if (r == 0) {
        D_0064C10C = 1;
    }
    return r;
}
