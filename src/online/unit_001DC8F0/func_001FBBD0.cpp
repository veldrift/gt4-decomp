extern char D_00645570[];
extern "C" char *func_004F9F70(void *, int);
extern "C" void func_004FA048(void *, char *);
extern "C" int func_001FBBD0(int arg0, int arg1, int arg2, int arg3) {
    char *base = D_00645570;
    char *entry = func_004F9F70(base, arg0);
    if (entry != 0) arg3 = *(int *)(entry + arg2);
    func_004FA048(base, entry);
    return arg3;
}
