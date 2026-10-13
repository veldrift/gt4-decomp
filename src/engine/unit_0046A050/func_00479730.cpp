typedef int s32;
typedef unsigned int u32;

struct Blk {
    s32 base;
    s32 count;
};

struct Obj {
    Blk blk;
    s32 tail;
};

extern "C" void func_00479710(int *arg0, s32 arg1);

extern "C" void func_00479730(Obj *arg0, s32 arg1)
{
    Blk *b = &arg0->blk;

    if (b->base != 0) {
        b->base = b->base + arg1;
    }

    u32 s2 = 0;

    if (b->count != 0) {
        s32 s1 = 0;

        do {
            s2 += 1;
            s32 a0 = b->base + s1;
            s1 += 0xC;
            func_00479710((int *)a0, arg1);
        } while (s2 < (u32)b->count);
    }

    s32 *t = &arg0->tail;

    if (*t != 0) {
        *t = *t + arg1;
    }
}
