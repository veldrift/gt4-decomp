/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern u16 D_006B0BE8[], D_006B0C10[];
extern "C" int func_004B8FE0(u16 *out, u16 *in, int mode) {
    int n, k, i;
    u16 *tab;
    if (in[0] != 0xA4) return 0;
    if (mode == 0x40) {
        n = 0x28;
        tab = D_006B0BE8;
        k = 1;
    } else if (mode == 0x5B) {
        n = 0xA;
        tab = D_006B0C10;
        k = 2;
    } else {
        return 0;
    }
    i = 0;
    if (n != 0) {
        u16 *q = tab + 1;
        u16 c = in[1];
        u16 *p = tab;
        
        do {
            if (c == *q) {
                out[0] = p[0] + k;
                out[1] = 0;
                return 1;
            }
            q += 2;
            i += 2;
            p += 2;
        } while (i < n);
    }
    return 0;
}
