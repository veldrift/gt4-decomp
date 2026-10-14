extern char D_00645570[], D_006959D0[], D_00696CB8[];
extern "C" int func_001F1368(void *) throw();
extern "C" void func_001F71B8(void *, int);
extern "C" void func_004FF200(char *, int, char *, const char *);
extern "C" int func_001F6930(char *ctx, int arg1, char *arg2) {
    if (!arg2) arg2 = D_006959D0;
    char *base = D_00645570;
    func_004FF200(base, arg1, arg2, D_00696CB8);
    int ret = func_001F1368(ctx);
    if (!ret) return ret;
    *(int *)(ctx + 0x1B8) = -1;
    func_001F71B8(ctx, 1);
    ret = 1;
    return ret;
}
