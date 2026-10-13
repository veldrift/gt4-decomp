struct Obj {
    char pad0[0x174];
    int n174;
};

struct Text5 { char c[5]; };

extern void *D_00624984;
extern "C" const Text5 D_0068F520;
extern "C" const char D_0068F528[];
extern "C" void func_00490A40(void *mgr, char *buf, int size, int value, const char *fmt);

extern "C" void func_001463E0(Obj *o, int size, char *buf) {
    int r = o->n174;
    if (r <= 0) {
        *(Text5 *)buf = D_0068F520;
        return;
    }
    func_00490A40(D_00624984, buf, size, r, D_0068F528);
}
