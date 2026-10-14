/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern u8 D_0064C0F4;
extern int D_0064C0FC, D_0064C100;
extern int *D_0064C104;
extern unsigned D_0086B3DC, D_0086B3D8;
extern "C" int func_0053A628(unsigned a, int *out, unsigned n) {
    int r = 5;
    if (D_0064C0F4 != 1) return r;
    if (D_0064C0FC == 0) return r;
    if (D_0064C100 == 0) return r;
    if (D_0064C104 == 0) return r;
    r = 2;
    if (a >= D_0086B3DC) return r;
    if (out == 0) return r;
    if (n < D_0086B3D8) return r;
    unsigned i = 0;
    if (D_0086B3D8 != 0) {
        do {
            *out = D_0064C104[a * D_0086B3D8 + i];
            i++;
            out++;
        } while (i < D_0086B3D8);
    }
    return 0;
}
