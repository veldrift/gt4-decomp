typedef int s32;
typedef unsigned int u32;

struct Blk {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
};

extern struct Blk D_0064C3D0;

extern "C" void func_00548A20(s32 arg0, s32 arg1) {
    struct Blk *g = &D_0064C3D0;
    u32 n;

    g->w4 = 0;
    n = (u32)(arg1 - 0x40) / 0x80C;
    g->wC = arg0;
    g->w0 = (s32)n;
    g->w10 = (arg0 + (s32)(n * 12) + 0x3F) & ~0x3F;
}
