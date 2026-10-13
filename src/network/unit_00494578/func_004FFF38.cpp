typedef int s32;

extern "C" s32 func_004F0C88(s32);
extern "C" s32 func_004F0CD0(s32, s32);

extern "C" s32 func_004FFF38(s32 arg0) {
    s32 var_v0;

    if (func_004F0C88(arg0) != 0) {
        var_v0 = func_004F0CD0(arg0, 0xF) != 0;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
