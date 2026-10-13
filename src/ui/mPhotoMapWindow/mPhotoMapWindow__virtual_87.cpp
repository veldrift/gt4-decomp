struct S {
    int m0;
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(char *, int);
};

extern "C" S *func_00206868(void *arg0);
extern "C" S *func_0025C300(S *arg0);
extern "C" void func_00263948(void *arg0, int arg1);

extern "C" void func_00207010(void *arg0, int arg1) {
    S *s;

    s = func_00206868(arg0);
    if (s != 0) {
        do {
            VEntry *e = (VEntry *)(s->vtbl + 0x2C0);
            e->fn((char *)s + e->delta, arg1);
            s = func_0025C300(s);
        } while (s != 0);
    }
    func_00263948(arg0, arg1);
}
