typedef int s32;

struct Pair {
    void *p;
    s32 n;
};

extern char D_00645570[];

extern "C" void func_004F0B08(void *arg0, s32 arg1);
extern "C" s32 func_004F0C38(void *arg0, const char *arg1);
extern "C" void func_004F8858(void *arg0, s32 arg1);

extern "C" void func_004FFEB0(void *arg0, s32 arg1, void *arg2) {
    Pair g;
    if (arg2 == 0) {
        arg2 = D_00645570;
    }
    g.p = arg2;
    g.n = 0;
    if (func_004F0C38(arg2, "MyMGCLConnectCallback") != 0) {
        func_004F0B08(g.p, g.n);
        return;
    }
    func_004F8858(arg2, arg1);
    func_004F0B08(g.p, g.n);
}
