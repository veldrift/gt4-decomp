/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern Obj *volatile D_00619018;
extern char D_005D9FA8[];
extern char D_00697970[];
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void mManager__structor_0(void *) throw();
extern "C" void func_003285A8(void *);
extern "C" void func_002ECDE0(void *);
extern "C" void func_002EAB90(void *, int, char *);
extern "C" void func_002EA590(void *, int);
extern "C" void func_00309348(void *, void *);

extern "C" void func_002117A0(void *arg0) {
    void *sp[2];
    void *loc;
    void **pl = &loc;
    if (!D_00619018) {
        void *p = func_00326750(0x30, 4, D_00697970);
        mManager__structor_0(p);
        D_00619018 = (Obj *)p;
        func_003285A8(p);
        func_002ECDE0(sp);
        Obj *o = D_00619018;
        void *s0 = sp[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x20);
        func_002EAB90(s0, e->fn((char *)o + e->delta), D_005D9FA8);
        func_002EA590(sp, 2);
    }
    *pl = D_00619018;
    func_00309348(arg0, pl);
}
