typedef unsigned int u32;
struct State { u32 mt[625]; int index; };
extern State D_0064B720;
extern "C" void func_00539670(u32);
extern "C" void func_005393B0(void) {
    u32 *p = D_0064B720.mt;
    u32 *q = p + 397;
    u32 *r = p + 2;
    if (D_0064B720.index >= 625) func_00539670(0x3579ABCD);
    D_0064B720.index = 0;
    u32 a = p[0], b = p[1];
    int n = 227;
    do {
        u32 *dst = p;
        u32 x = *q++ ^ (((a & 0x80000000) | (b & 0x7FFFFFFF)) >> 1);
        if (b & 1) x ^= 0x9908B0DF;
        a = b;
        p++;
        *dst = x;
        b = *r++;
    } while (--n);
    q = D_0064B720.mt;
    n = 396;
    do {
        u32 *dst = p;
        u32 x = *q++ ^ (((a & 0x80000000) | (b & 0x7FFFFFFF)) >> 1);
        if (b & 1) x ^= 0x9908B0DF;
        a = b;
        p++;
        *dst = x;
        b = *r++;
    } while (--n);
    b = D_0064B720.mt[0];
    u32 x = *q ^ (((a & 0x80000000) | (b & 0x7FFFFFFF)) >> 1);
    if (b & 1) x ^= 0x9908B0DF;
    *p = x;
}
