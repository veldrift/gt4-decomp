struct Obj { int refs; char *vtbl; };
struct Entry { short delta; short index; int (*fn)(void *); };
extern Obj *volatile D_00618DD8;
extern char D_006959A0[];
extern "C" void mNetwork__structor_0(void *) throw();
extern "C" void func_002EA590(void *, int);
extern "C" int func_002EAB90(int, int, void *);
extern "C" void func_002ECDE0(void *);
extern "C" void func_00309348(void *, void *);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_005D4C60();
extern "C" void func_001DC8F0(void *dst) {
    int h[4];
    Obj *rhs[4];
    Obj **pr = rhs;
    Obj *volatile *pg = &D_00618DD8;
    if (!*pg) {
        Obj *p = (Obj *)func_00326750(0x1FC, 4, D_006959A0);
        mNetwork__structor_0(p);
        *pg = p;
        func_003285A8(p);
        func_002ECDE0(h);
        Obj *o = *pg;
        int handle = h[0];
        Entry *e = (Entry *)(o->vtbl + 0x20);
        func_002EAB90(handle, e->fn((char *)o + e->delta), (void *)func_005D4C60);
        func_002EA590(h, 2);
    }
    *pr = *pg;
    func_00309348(dst, pr);
}
