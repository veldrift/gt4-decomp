struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Obj89 {
    int m0;
    char *vtbl;
};

extern "C" void func_002639A8(Obj89 *arg0, int arg1);
extern "C" Obj89 *func_00206868(Obj89 *arg0);
extern "C" Obj89 *func_0025C300(Obj89 *arg0);

extern "C" void func_00207110(Obj89 *arg0, int arg1) {
    Obj89 *s0;

    func_002639A8(arg0, arg1);
    s0 = func_00206868(arg0);
    if (s0 != 0) {
        do {
            VEntry *e = (VEntry *)(s0->vtbl + 0x2D0);
            e->fn((char *)s0 + e->delta, arg1);
            s0 = func_0025C300(s0);
        } while (s0 != 0);
    }
}
