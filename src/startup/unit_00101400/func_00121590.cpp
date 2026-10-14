typedef int s32;

extern "C" char D_00123588[];
extern "C" char D_001235B0[];
extern "C" char D_00618730[];
extern "C" char D_00618750[];

extern "C" void func_004A1638(s32 arg0);
extern "C" void func_004A2808(s32 arg0, float arg1);
extern "C" s32 func_00123640(s32 arg0, s32 arg1);
extern "C" s32 func_00123660(s32 arg0, s32 arg1);
extern "C" void func_001218C0(s32 arg0, s32 arg1, char *arg2, char *arg3, float arg4, float arg5);
extern "C" void func_004AB040(s32 arg0);

extern "C" void func_00121590(s32 arg0, s32 arg1, float fparg0) {
    func_004A1638(6);
    func_004A2808(0x64, 0.5f);
    if (func_00123640(arg0, arg1) != 0) {
        float v = 50.0f;
        if (arg1 != 0) {
            v = -50.0f;
        }
        func_001218C0(arg0, arg1, D_00123588, D_00618730 + arg1 * 16, fparg0, v);
    }
    if (func_00123660(arg0, arg1) != 0) {
        float w = 50.0f;
        if (arg1 != 0) {
            w = -50.0f;
        }
        func_001218C0(arg0, arg1, D_001235B0, D_00618750 + arg1 * 16, fparg0, w);
    }
    func_004AB040(6);
}
