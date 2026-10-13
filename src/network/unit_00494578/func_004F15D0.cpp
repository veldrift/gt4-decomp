typedef int s32;

struct Pair {
    void *p;
    s32 n;
};

extern char D_00645570[];
extern char D_006C0350[];

extern "C" void func_004F0B08(void *arg0, s32 arg1);
extern "C" s32 func_004F0C38(void *arg0, const char *arg1);

extern "C" void func_004F15D0(void *arg0, void *arg1) {
    Pair g;
    if (arg1 == 0) {
        arg1 = D_00645570;
    }
    g.p = arg1;
    g.n = 0;
    if (func_004F0C38(arg1, D_006C0350) != 0) {
        func_004F0B08(g.p, g.n);
        return;
    }
    func_004F0B08(g.p, g.n);
}
