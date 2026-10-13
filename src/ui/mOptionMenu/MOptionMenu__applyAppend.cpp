typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Target {
    int m0;
    char *vtbl;
};

struct H {
    Target *p;
    int pad[3];
};

struct T {
    void *v;
    void *get() { return v; }
    int pad[3];
};

extern "C" void func_002C7310(H *h, void *a);
extern "C" void func_002C72B8(H *h, int in_chrg);
extern "C" void func_0022AD20(T *t, void *a);
extern "C" void func_0022ACC8(T *t, int in_chrg);

extern "C" void func_002C7A08(void *self, void *a1, int count, void *arg) {
    if (count > 0) {
        T t;
        func_0022AD20(&t, arg);
        H h;
        H *ph = &h;
        func_002C7310(ph, a1);
        Target *o = ph->p;
        VEntry *e = (VEntry *)(o->vtbl + 0x340);
        e->fn((char *)o + e->delta, t.get());
        func_002C72B8(ph, 2);
        func_0022ACC8(&t, 2);
    }
}
