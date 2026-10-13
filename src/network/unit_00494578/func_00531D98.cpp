typedef int s32;
typedef unsigned char u8;

struct Obj00531CD8 {
    char pad0[0x14C];
    s32 unk14C;
};

extern "C" s32 func_005A48D8(void *, s32, s32);
extern "C" s32 func_00531CD8(s32 *arg0, struct Obj00531CD8 *arg1);
extern "C" s32 func_00531D40(s32 arg0, s32 arg1);

extern "C" s32 func_00531D98(s32 *arg0, struct Obj00531CD8 *arg1) {
    s32 ret = 0x17;

    if (arg0 == 0) {
        return ret;
    }
    func_005A48D8(arg0, 0, 0xC);
    ret = 0x17;
    if (arg1 == 0) {
        return ret;
    }
    ret = func_00531CD8(arg0, arg1);
    if (ret != 0) {
        return ret;
    }
    ret = func_00531D40((s32)((char *)arg0 + 4), (s32)arg1);
    if (ret != 0) {
        return ret;
    }
    *(s32 *)((char *)arg0 + 8) =
        *(s32 *)((char *)arg0 + 4) + arg1->unk14C;
    return ret;
}
