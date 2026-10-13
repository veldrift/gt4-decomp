typedef int s32;

struct Blk8 {
    s32 a;
    s32 b;
};

extern "C" void func_0044CC18(s32 arg0, Blk8 *arg1, Blk8 *arg2, s32 arg3);

extern "C" void func_0044CB88(s32 arg0) {
    s32 v0[8];
    s32 v1[2];
    Blk8 *p0 = (Blk8 *)v0;
    Blk8 *p1 = (Blk8 *)v1;
    p0->a = 0;
    p0->b = 0;
    p1->a = 0;
    p1->b = 0;
    func_0044CC18(arg0, p0, p1, 1);
}
