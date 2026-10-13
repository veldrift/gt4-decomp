typedef int s32;

struct P8 {
    s32 a;
    s32 b;
};

struct Obj0053EE38 {
    s32 p0[3];
    struct P8 blk;
    s32 p14;
    s32 f18;
    s32 p1c[8];
    s32 f3C;
};

extern "C" s32 func_0053EE38(struct Obj0053EE38 *arg0, struct P8 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        return 2;
    }
    if (arg0->f3C != 0) {
        return 0xD6DA;
    }
    if (arg1 == 0) {
        return 2;
    }
    if (arg2 == 0) {
        return 2;
    }
    *arg1 = arg0->blk;
    *arg2 = arg0->f18;
    return 0;
}
