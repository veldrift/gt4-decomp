/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
extern "C" void func_003452F0(void *);
extern "C" void func_003454A8(void *);
extern "C" void func_00345520(void *);
extern "C" void func_00345598(void *);
extern "C" void func_00467148(void *, int);
extern "C" void func_004673D0(void *);
static inline u8 flag(unsigned long v, unsigned long mask) { return (v >> 3) & mask; }
extern "C" void func_00343D78(char *o, int mode) {
    char *p = o + 0x104;
    if (mode == 4) mode = flag(*(u8 *)(p + 0x4B1), 2);
    if (!*(u8 *)(p + 0x4B2)) {
        u8 v = *(u8 *)(p + 0x467);
        *(u8 *)(p + 0x4B2) = 1;
        if ((unsigned)(u8)(v + 0xFE) < 3) return;
    }
    if (*(s8 *)(p + 0x466) == 0) {
        char *q = o + 0x14;
        func_004673D0(q);
        func_00467148(q, *(u8 *)(*(char **)(o + 0x10) + 0x31));
    }
    int v = *(u8 *)(*(char **)(o + 4) + 0xCBDE);
    mode = v == 1 ? (mode ? mode : v) : mode;
    switch (mode) {
    case 3: return func_003454A8(o);
    case 1: return func_00345520(o);
    case 2: return func_00345598(o);
    case 0:
    default: return func_003452F0(o);
    }
}
