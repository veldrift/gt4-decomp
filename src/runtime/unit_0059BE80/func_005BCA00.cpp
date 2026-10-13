typedef int s32;

extern "C" char D_008A1C80[];
extern "C" s32 func_005ADB90(void);
extern "C" s32 func_005BC640(void);
extern "C" void func_00575DA0(s32);

extern "C" s32 func_005BCA00(void) {
    char *base = D_008A1C80;
    s32 s0 = *(s32 *)(base + func_005ADB90() * 4);
    if (s0 == 0) {
        s0 = func_005BC640();
        s32 v1 = *(s32 *)(base + func_005ADB90() * 4);
        if (v1 != 0) {
            func_00575DA0(v1);
        }
        s32 *slot = (s32 *)(base + func_005ADB90() * 4);
        *slot = s0;
    }
    return s0;
}
