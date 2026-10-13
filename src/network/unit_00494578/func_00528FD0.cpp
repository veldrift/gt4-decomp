typedef int s32;

struct Obj {
    s32 tag;
    char pad0[0x18];
    s32 f1c;
    char pad1[0x14];
    s32 f34;
};

extern "C" s32 func_00528FD0(s32 arg0, Obj *arg1, s32 arg2, s32 *arg3) {
    *arg3 = 0;
    if (arg0 == 0) {
        return 0xD2F2;
    }
    if (arg1 == 0) {
        return 0xD2F3;
    }
    if (arg1->tag != 0xD) {
        return 0xD2F3;
    }
    if (arg2 == 0) {
        *arg3 = arg1->f1c;
        return 0;
    }
    if (arg2 == 1) {
        *arg3 = arg1->f34;
        return 0;
    }
    return 2;
}
