typedef int s32;

extern "C" s32 D_00622F4C;
extern "C" void func_00119818(void *arg0);
extern "C" void func_00119AE8(void *arg0);
extern "C" void func_003EF0E8(void *arg0, void *arg1, s32 arg2);

extern "C" void func_001197B8(void *arg0) {
    s32 base = D_00622F4C;
    if (*(signed char *)(base + 0x38C20) != 0) {
        func_00119AE8(arg0);
    } else {
        func_003EF0E8(arg0, (char *)base + 0x44, 0);
    }
    func_00119818(arg0);
}
