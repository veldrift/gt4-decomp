typedef int s32;
extern char D_006888E0[];
extern "C" void func_0046F0B8(void *, s32);
extern "C" void func_00470D00(void *, s32);
extern "C" void func_005C1628(int value);
extern "C" void func_0046C098(char *arg0, s32 arg1) {
    char *p = arg0 + 0xC;
    *(s32 *)(arg0 + 0x8E8) = (s32)D_006888E0;
    func_0046F0B8(arg0 + 0x85C, 2);
    func_00470D00(p, 2);
    if (arg1 & 1) {
        return func_005C1628((s32)arg0);
    }
}
