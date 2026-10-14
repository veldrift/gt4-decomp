typedef int s32;

extern char D_00645570[];

extern "C" char *func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" void func_005A609C(char *arg0, char *arg1);

extern "C" void func_001F6FE8(char *arg0, s32 arg1) {
    char *s2 = func_004FA008(D_00645570);
    if (s2 != 0) {
        func_005A609C(s2 + arg1, arg0);
    }
    func_004FA048(D_00645570, s2);
}
