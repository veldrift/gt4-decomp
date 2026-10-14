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

extern "C" void func_002434C8(void *arg0, void *arg1);
extern "C" void func_00243470(void *arg0, int arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void func_00203620(void *arg0, int arg1);

extern "C" void MTextFace__set_color(void *self, void *a1, int count, void *arg) {
    if (count > 0) {
        H h;
        func_002434C8(&h, a1);
        T t;
        func_00203678(&t, arg);
        Target *o = h.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1E0);
        e->fn((char *)o + e->delta, (char *)t.get() + 0x10);
        func_00203620(&t, 2);
        func_00243470(&h, 2);
    }
}
