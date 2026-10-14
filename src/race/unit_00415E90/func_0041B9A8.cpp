typedef int s32;

extern "C" void Numerical_Math__Quaternion__rotate(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0041B9A8(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    Numerical_Math__Quaternion__rotate(arg0, arg1 + 0x10, arg1 + 0x30);
    return s0;
}
