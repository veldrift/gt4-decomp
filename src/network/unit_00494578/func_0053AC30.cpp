typedef int s32;
typedef unsigned int u32;

struct Obj0053AC30 {
    u32 unk0;
    s32 unk4;
};

extern "C" s32 func_0053AC30(struct Obj0053AC30 *arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    u32 t = arg0->unk0;
    if (t >= 0x10C5) {
        return 0x641;
    }
    *arg1 = t * 0xF4240 + arg0->unk4;
    return 0;
}
