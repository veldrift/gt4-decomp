typedef int s32;
typedef unsigned int u32;

struct Obj0053AB70 {
    u32 unk0;
    u32 unk4;
};

extern "C" s32 func_0053AB70(struct Obj0053AB70 *arg0, s32 *arg1) {
    struct Obj0053AB70 *p = arg0;
    s32 *q = arg1;
    if (p == 0) {
        return 2;
    }
    if (q == 0) {
        return 2;
    }
    u32 t = p->unk0;
    u32 k = 1000000;
    s32 ret = 0;
    *q = t;
    *q = t + p->unk4 / k;
    return ret;
}
