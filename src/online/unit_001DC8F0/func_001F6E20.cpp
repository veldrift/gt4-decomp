typedef int s32;

extern char D_00645570[];

extern "C" char *func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" void func_005A6AB0(char *dst, char *src, s32 n);

extern "C" void func_001F6E20(s32 unused, char *arg1) {
    char *base = D_00645570;
    char *s1 = func_004FA008(base);
    if (s1 != 0) {
        func_005A6AB0(s1 + 0x7A, arg1, 0x40);
    }
    func_004FA048(base, s1);
}
