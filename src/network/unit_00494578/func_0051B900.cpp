struct Item { char pad[0xC]; int value; };
extern "C" Item *func_00535C88(int *, unsigned int);
extern "C" int func_0051B900(int *out, int *ctx, unsigned int index) {
    if (!out) return 0x17;
    *out = 0;
    if (index < 0x40) {
        Item *p = func_00535C88(ctx, index);
        if (p) {
            *out = p->value;
        }
        return 0;
    }
    return 8;
}
