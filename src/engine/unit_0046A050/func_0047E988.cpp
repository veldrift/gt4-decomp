typedef int s32;
typedef unsigned int u32;

struct Blk {
    s32 base;
    s32 count;
};

struct Obj {
    char pad[0x10];
    Blk blk;
};

extern "C" void func_0047EA98(Obj *arg0, s32 arg1);

extern "C" void func_0047E988(Obj *arg0, s32 arg1)
{
    Blk *b = &arg0->blk;

    if (b->base != 0) {
        b->base = b->base + arg1;
    }

    u32 s1 = 0;

    if (b->count != 0) {
        do {
            s32 off = (s32)(s1 << 3);
            s1 += 1;
            func_0047EA98((Obj *)(b->base + off), arg1);
        } while (s1 < (u32)b->count);
    }
}
