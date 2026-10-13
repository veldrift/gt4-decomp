typedef int s32;

extern "C" void func_00490CA0(s32 arg0);

extern s32 D_00624980;

extern "C" void func_0044D950(s32 *arg0) {
    if (*arg0 == 0) {
        *arg0 = 1;
        func_00490CA0(D_00624980);
    }
}
