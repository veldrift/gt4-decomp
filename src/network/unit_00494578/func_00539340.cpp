typedef unsigned int u32;
extern char D_0064B720[];
extern "C" void func_00539340(u32 *src, u32 n) {
    u32 *p = (u32 *)D_0064B720;
    u32 v = -1U;
    p[0x271] = 0x26F;
    n = n >= 0x270 ? 0x26F : n;
    *p = -1;
    p++;
    int count = 0x270;
    u32 k = 0x10DCD;
    do {
        if (n != 0) {
            v ^= *src++;
            n--;
        }
        v = (v << 5) | (v >> 27);
        v *= k;
        count--;
        *p++ = v;
    } while (count != 0);
}
