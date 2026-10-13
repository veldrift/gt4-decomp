typedef int s32;
typedef unsigned int u32;

struct Blk {
    s32 base;
    s32 count;
};

struct Obj {
    Blk b0;
    s32 x8;
    s32 pad_c;
    Blk b1;
    Blk b2;
};

extern "C" void func_00474B08(char *arg0, s32 arg1);
extern "C" void func_00474F00(int *arg0, int arg1);
extern "C" void func_00474F18(int *arg0, int arg1);

extern "C" void func_00474430(Obj *arg0, s32 arg1)
{
    s32 s3 = arg1;

    if (arg0->b0.base != 0) {
        arg0->b0.base = arg0->b0.base + s3;
    }

    u32 s2 = 0;

    if (arg0->b0.count != 0) {
        s32 s0 = 0;

        do {
            s2 += 1;
            s32 a0 = arg0->b0.base + s0;
            s0 += 0x28;
            func_00474B08((char *)a0, s3);
        } while (s2 < (u32)arg0->b0.count);
    }

    s32 *t = &arg0->x8;

    if (*t != 0) {
        *t = *t + s3;
    }

    Blk *p = &arg0->b1;

    if (p->base != 0) {
        p->base = p->base + s3;
    }

    u32 s4 = 0;

    if (p->count != 0) {
        s32 off = 0;

        do {
            s4 += 1;
            s32 a0 = p->base + off;
            off += 0xC;
            func_00474F18((int *)a0, s3);
        } while (s4 < (u32)p->count);
    }

    Blk *q = &arg0->b2;

    if (q->base != 0) {
        q->base = q->base + s3;
    }

    u32 i = 0;

    if (q->count != 0) {
        do {
            s32 a0 = (s32)(i << 3);
            i += 1;
            func_00474F00((int *)(q->base + a0), s3);
        } while (i < (u32)q->count);
    }
}
