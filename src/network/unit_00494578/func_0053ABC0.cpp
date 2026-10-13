typedef int s32;
typedef unsigned int u32;

struct Obj0053ABC0 {
    u32 unk0;
    u32 unk4;
};

extern "C" s32 func_0053ABC0(struct Obj0053ABC0 *arg0, s32 *arg1) {
    struct Obj0053ABC0 *p = arg0;
    s32 *q = arg1;
    s32 ret = 2;

    if (p == 0) {
        return 2;
    }
    if (q == 0) {
        return 2;
    }
    u32 t = p->unk0;
    ret = 0x641;
    if (t > 0x418935) {
        return ret;
    }
    ret = 0;
    *q = t * 1000 + p->unk4 / 1000;
    return ret;
}
