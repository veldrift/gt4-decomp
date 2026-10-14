/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long long s64;
typedef unsigned char u8;

struct Sub { char pad[0xF920]; u8 tab[6][2][2]; };

extern "C" s64 func_0035C6D8(char *o, int a, int b, int c) {
    s64 r = -1;
    if (a < 0) return r;
    if (a >= *(int *)(o + 0xF8A0)) return r;
    if (b < 0) return r;
    if (b >= 2) return r;
    Sub *base = (Sub *)(o + 8);
    int lo = base->tab[a][b][0];
    int hi = base->tab[a][b][1];
    if (c < lo) return r;
    if (hi < c) return r;
    int index = b * 5;
    index += a * 10;
    index += c - lo;
    return *(s64 *)(o + index * 8 + 0xF940);
}
