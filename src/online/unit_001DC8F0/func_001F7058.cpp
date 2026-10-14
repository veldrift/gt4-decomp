typedef int s32;

extern char D_00645570[];
extern char D_00696CC0[];

extern "C" char *func_004F9F70(char *arg0, void *arg1);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" void func_005A609C(char *arg0, char *arg1);

extern "C" void func_001F7058(void *arg0, char *arg1, s32 arg2) {
    char *s2 = func_004F9F70(D_00645570, arg0);
    char *dst;
    if (s2 != 0) {
        dst = s2 + arg2;
    } else {
        dst = D_00696CC0;
    }
    func_005A609C(arg1, dst);
    func_004FA048(D_00645570, s2);
}
