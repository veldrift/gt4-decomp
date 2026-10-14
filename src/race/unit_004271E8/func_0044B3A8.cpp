typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_0044B680(void *, void *, void *, void *, int);

extern "C" void func_0044B3A8(u8 *tab) {
    u32 v = 1;
    u32 i;
    func_005A48D8(tab + 0x100, 0, 0x100);
    func_005A48D8(tab, 0, 0x100);
    for (i = 0; i < 0x100; i++) {
        u8 b = v & 0xFF;
        tab[0x100 + i] = b;
        tab[b] = i;
        v = (v * 0x2D) % 257u;
    }
}

extern "C" void func_0044B450(void *a, void *b, int c) {
    long z = 0;
    func_0044B680(a, b, &z, &z, c);
}

extern "C" void func_0044B478(void *a, void *b, void *c, int d) {
    long z = 0;
    func_0044B680(a, b, c, &z, d);
}
