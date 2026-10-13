typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0x60];
    void *unk60;
    char pad64[0x6C - 0x64];
};

struct Rec16 {
    char b[16];
};

extern "C" s32 func_005657E0(void *o, s32 i, s32 *out);

extern "C" s32 func_00553460(Obj *arg0, Rec16 *arg1) {
    s32 idx[4];
    Rec16 *items = (Rec16 *)((char *)arg0 + 0x6C);
    s32 ret;
    s32 e = func_005657E0(arg0->unk60, 0, idx);
    if (e != 0) {
        ret = e;
    } else {
        ret = 0;
        *arg1 = items[idx[0]];
    }
    return ret;
}
