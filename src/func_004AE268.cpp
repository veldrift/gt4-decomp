typedef int s32;

extern "C" void func_004AE370(s32 arg0, s32 arg1, s32 *arg2, s32 arg3);

extern "C" s32 func_004AE268(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp[2];
    sp[0] = arg2;
    sp[1] = arg3;
    func_004AE370(arg0, arg1, sp, arg4);
    return arg0;
}
