typedef int s32;

extern "C" void func_004187A0(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0041B860(s32 arg0, s32 arg1, s32 arg2) {
    func_004187A0(arg0, arg2, arg1 + 0x30);
    return arg0;
}
