typedef int s32;

struct Entry {
    s32 flags;
    char pad[0x1C];
};

extern Entry D_008A05B0[];

extern "C" s32 func_00534A08(void) {
    Entry *base = D_008A05B0;
    Entry *e = (Entry *)((char *)base + 0x10);
    s32 i;
    for (i = 0; i < 0x7F; i++) {
        if (e->flags == 0) return i;
        e++;
    }
    return 0x7F;
}
