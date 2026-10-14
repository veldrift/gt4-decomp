/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned char D_0064C0F4;
extern int D_0064C100, D_0064C0FC, D_0064C0F8, D_0064C104, D_0064C108;
extern int D_0086B3E0;
extern unsigned int D_0086B3D8, D_0086B3DC;
extern "C" int func_00538BF8(int *, unsigned long) throw();
extern "C" int func_00539FD8(int a, unsigned int b, unsigned int c, int d) {
    unsigned char *ready = &D_0064C0F4;
    if (*ready) return 1000;
    if (b > 256) return 2;
    if (c > 256) return 2;
    D_0086B3D8 = b;
    D_0086B3DC = c;
    D_0086B3E0 = a;
    D_0064C108 = d;
    int r = func_00538BF8(&D_0064C100, c * 4);
    if (r) return r;
    unsigned long size = c * b * 4;
    r = func_00538BF8(&D_0064C0FC, size);
    if (r) return r;
    r = func_00538BF8(&D_0064C0F8, (unsigned int)a);
    if (r) return r;
    r = func_00538BF8(&D_0064C104, size);
    if (r == 0) *ready = 1;
    return r;
}
