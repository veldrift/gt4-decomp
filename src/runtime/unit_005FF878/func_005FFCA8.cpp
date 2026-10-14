typedef int s32;

extern "C" void func_004187A0(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_005FFCA8(s32 arg0, s32 arg1, s32 arg2) {
    func_004187A0(arg0, arg2, arg1 + 0x50);
    return arg0;
}
