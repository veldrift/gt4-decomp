extern "C" int func_001F0D38(int k);
extern "C" void *func_001F1368(void *ctx);
extern "C" void func_00215298(int n);
extern "C" int func_004F6BA0(char *d, int a, int v);
extern char D_00645570[];

extern "C" void *func_001F21D8(void *arg0)
{
    int v = func_001F0D38(*(int *)((char *)arg0 + 0x1B4));
    while (!func_004F6BA0(D_00645570, 2, v))
        func_00215298(1);
    return func_001F1368(arg0);
}
