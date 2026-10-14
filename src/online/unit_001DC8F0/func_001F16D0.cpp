extern "C" int func_001F0D38(int k);
extern "C" int func_001F1368(void *ctx);
extern "C" void mUpdateContext__Sync(int n);
extern "C" int func_004F1038(char *d, int value);
extern char D_00645570[];

extern "C" int func_001F16D0(void *arg0)
{
    int v = func_001F0D38(*(int *)((char *)arg0 + 0x1B4));
    while (!func_004F1038(D_00645570, v))
        mUpdateContext__Sync(1);
    return func_001F1368(arg0);
}
