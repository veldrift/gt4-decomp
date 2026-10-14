typedef int s32;

extern char D_00645570[];

extern "C" char *func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" s32 func_001F0DC0(void *arg0);

extern "C" void func_001F6BF0(s32 unused, s32 arg1) {
    char *base = D_00645570;
    char *s1 = func_004FA008(base);
    if (s1 != 0) {
        *(signed char *)(s1 + 0x35) = (signed char)func_001F0DC0((void *)arg1);
    }
    func_004FA048(base, s1);
}
