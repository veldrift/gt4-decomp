typedef int s32;

struct Obj {
    char pad0[0x60];
    void *unk60;
    char pad64[0x6C - 0x64];
};

struct Blk36 {
    s32 w[9];
};

extern "C" s32 func_005657E0(void *o, s32 i, s32 *out);

extern "C" s32 func_00565E50(Obj *arg0, s32 arg1, Blk36 *arg2) {
    s32 idx[4];
    Blk36 *items = (Blk36 *)((char *)arg0 + 0x6C);
    s32 ret;
    s32 e = func_005657E0(arg0->unk60, arg1, idx);
    if (e != 0) {
        ret = e;
    } else {
        ret = 0;
        *arg2 = items[idx[0]];
    }
    return ret;
}
