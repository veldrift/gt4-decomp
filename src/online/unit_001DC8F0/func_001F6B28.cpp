extern char D_00645570[];

extern "C" char *func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" char *func_005A609C(char *arg0, const char *arg1);

extern "C" void func_001F6B28(void *unused, char *arg1) {
    char *base = D_00645570;
    char *s1 = func_004FA008(base);
    if (s1 != 0) {
        func_005A609C(s1 + 4, arg1 ? arg1 : base + 0xFE0);
    }
    func_004FA048(base, s1);
}
