typedef int s32;
typedef unsigned int u32;

struct Blk {
    s32 base;
    s32 count;
};

struct Obj {
    char pad[4];
    Blk blk;
};

extern "C" void func_0047EEC8(int *arg0, s32 arg1);

extern "C" void func_0047EC10(Obj *arg0, s32 arg1)
{
    Blk *b = &arg0->blk;
    s32 s3 = arg1;

    if (b->base != 0) {
        b->base = b->base + s3;
    }

    u32 s2 = 0;

    if (b->count != 0) {
        s32 s1 = 0;

        do {
            s2 += 1;
            s32 a0 = b->base + s1;
            s1 += 0x14;
            func_0047EEC8((int *)a0, s3);
        } while (s2 < (u32)b->count);
    }
}
