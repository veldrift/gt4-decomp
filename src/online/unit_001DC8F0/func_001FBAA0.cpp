extern char D_00645570[];

extern "C" int func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);

extern "C" void func_001FBAA0(signed char arg0, int arg1)
{
    signed char c = arg0;
    int r = func_004FA008(D_00645570);
    if (r != 0) {
        *(signed char *)(r + arg1) = c;
    }
    func_004FA048(D_00645570, (char *)r);
}
