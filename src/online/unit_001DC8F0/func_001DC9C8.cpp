typedef int s32;

extern "C" s32 func_0057F260(void *arg0);
extern "C" s32 func_001F1330(void *arg0, const char *arg1);
extern "C" void func_005A609C(void *arg0, s32 arg1);

extern "C" void *func_001DC9C8(char *arg0) {
    char *s1 = arg0 + 0x20;
    if (func_0057F260(s1) == 0) {
        func_005A609C(s1, func_001F1330(arg0, "emplate.scea.com"));
    }
    return s1;
}
