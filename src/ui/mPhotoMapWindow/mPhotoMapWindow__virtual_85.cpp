struct S {
    int m0;
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(char *, void *);
};

extern "C" void func_002638E8(void *arg0, void *arg1);
extern "C" S *func_00206868(void *arg0);
extern "C" S *func_0025C300(S *arg0);

extern "C" void func_00206F18(void *arg0, void *arg1) {
    S *s;

    func_002638E8(arg0, arg1);
    s = func_00206868(arg0);
    while (s != 0) {
        VEntry *e = (VEntry *)(s->vtbl + 0x2B0);
        e->fn((char *)s + e->delta, arg1);
        s = func_0025C300(s);
    }
}
