typedef int s32;

extern char D_00645570[];
extern char D_006959D0[];
extern char D_006959D8[];
extern char D_00696CB8[];

extern "C" s32 func_001F1368(void *arg0);
extern "C" void func_001F71B8(void *unused, s32 arg1);
extern "C" void func_004FF760(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4, const char *arg5, s32 arg6);
extern "C" void func_004FFB38(void *arg0);

extern "C" s32 func_001F6828(void *arg0, char **arg1, s32 arg2, s32 arg3, char *arg4, s32 arg5) {
    char *s;
    char *p;
    char *q;
    s32 n;
    char *var;
    s = arg4;
    func_004FFB38(D_00645570);
    if (func_001F1368(arg0) == 0) {
        return 0;
    }
    if (arg3 <= 0) {
        return 0;
    }
    if (s == 0) {
        s = D_006959D0;
    }
    p = *arg1;
    n = *(s32 *)(p - 0x10);
    q = p + n;
    if (n == 0) {
        var = D_006959D8;
    } else {
        *q = 0;
        var = *arg1;
    }
    func_004FF760(D_00645570, var, arg2, arg3, s, D_00696CB8, arg5);
    if (func_001F1368(arg0) != 0) {
        *(s32 *)((char *)arg0 + 0x1B8) = -1;
        func_001F71B8(arg0, 0);
        return 1;
    }
    return 0;
}
