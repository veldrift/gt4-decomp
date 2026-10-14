typedef int s32;
typedef unsigned int u32;
struct S {
    char pad[0x800C];
    s32 tbl[0x100];
    u32 n;
};
extern "C" s32 func_00541D78(S *s, s32 v) {
    if (s == 0) return 2;
    if (v != 0) {
        u32 n = s->n;
        if (n < 0x100) {
            s->tbl[n] = v;
            s->n = n + 1;
            return 0;
        }
        return 0xD8CD;
    }
    return 2;
}
