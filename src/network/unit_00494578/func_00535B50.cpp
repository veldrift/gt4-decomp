struct X { char pad[0x15C]; unsigned f15C; };
extern char D_008686B8[];

extern "C" X *func_00535B08(void) throw();
static inline X *getslot(char *base, int off) { return *(X **)(off + (int)base); }
extern "C" int func_00535B50(unsigned idx, X **out) {
    int off;
    X **slot;
    if (out == 0) return 0x17;
    *out = 0;
    if (!(idx < 4)) return 0x17;
    off = idx * 4;
    slot = (X **)(D_008686B8 + off);
    if (*slot == 0) {
        X *x = func_00535B08();
        *slot = x;
        if (x == 0) return 0x16;
        x->f15C = idx;
    }
    *out = getslot(D_008686B8, off);
    return 0;
}
