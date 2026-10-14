/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
static inline int load(u16 *p) { return *p; }
extern "C" s32 func_004C4ED0(u16 *s, s32 n) {
    s32 i = 0;
    s32 c;
    while ((c = load(s)) != 0 && (n == 0 || i < n)) {
        s32 idx = i;
        i++;
        if ((u16)(c + 0x5E5E) < 4) return idx;
        s++;
    }
    return -1;
}
