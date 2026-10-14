typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_0052E158(Obj *arg0, s32 *arg1) {
    if (arg1 == 0) {
        return 2;
    }
    *arg1 = arg0->unk8 - arg0->unkC;
    if (*arg1 < 0) {
        *arg1 = 0;
    }
    return 0;
}
