typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

struct Blk {
    s32 m0;
    s32 m4;
    s32 m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    s32 m2C;
    s32 m30;
    s32 m34;
};

extern "C" char D_00863BC8[];
extern "C" char D_00863C00[];
extern "C" s32 func_0053A860(void *self);

extern "C" void func_00522138(void)
{
    Blk *g = (Blk *)D_00863BC8;
    g->m8 = 0;
    g->mC = 0;
    g->m10 = 0;
    g->m14 = 0;
    g->m18 = 0;
    g->m1C = 0;
    g->m20 = 0;
    g->m24 = 0;
    g->m28 = 0;
    g->m2C = 0;
    g->m30 = 0;
    g->m34 = 0;
    func_0053A860(g);
    Pair *d = (Pair *)D_00863C00;
    *d = *(Pair *)g;
}
