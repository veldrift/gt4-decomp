typedef signed char s8;
typedef int s32;

extern "C" void func_00530618(s32 arg0, s32 arg1);
extern "C" s8 *D_0064B47C;

extern "C" s32 func_00532D58(s32 arg0, s32 arg1) {
    s32 var_v0;
    s8 *p;

    var_v0 = 0x17;
    if (arg0 != 0) {
        func_00530618(arg0, arg1);
        p = D_0064B47C;
        var_v0 = 0;
        *(s32 *)(p + 0x58) = arg1;
    }
    return var_v0;
}
