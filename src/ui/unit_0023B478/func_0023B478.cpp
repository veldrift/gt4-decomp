/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VT { s16 off; s16 pad; s32 (*fn)(void *); };
struct Obj { char pad[4]; char *vt; };
extern "C" Obj *volatile D_006191A8;
extern "C" char D_005DBF48[];
extern "C" char D_00698C90[];
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void mShell__structor_0(void *) throw();
extern "C" void func_003285A8(void *);
extern "C" void func_002ECDE0(void *);
extern "C" void func_002EAB90(void *, s32, void *);
extern "C" void func_002EA590(void *, int);
extern "C" void func_00309348(void *, void *);

extern "C" void func_0023B478(void *arg0) {
    void *sp[4];
    void *sp10[4];
    void **q = sp10;
    Obj *volatile *gp = &D_006191A8;
    if (*gp == 0) {
        void *p = func_00326750(0x14, 4, D_00698C90);
        mShell__structor_0(p);
        *gp = (Obj *)p;
        func_003285A8(p);
        func_002ECDE0(sp);
        Obj *g = *gp;
        void *h = sp[0];
        VT *v = (VT *)(g->vt + 0x20);
        func_002EAB90(h, v->fn((char *)g + v->off), D_005DBF48);
        func_002EA590(sp, 2);
    }
    q[0] = *gp;
    func_00309348(arg0, q);
}
