/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Vec { int pad; int *b; int *e; int *c; int more[4]; };
struct H { void *p; int pad[3]; };
struct T { int *it; void *h1; int pad[2]; };
struct Info { const char *name; };
extern "C" void mDefine__read(void *, void *) throw();
extern "C" void func_002F4210(void *, int);
extern "C" void hCode__structor_0(void *, Vec *);
extern "C" void func_002F4A10(void *, void *);
extern "C" void func_00309348(void *, void *);
extern "C" void *func_00326750(unsigned, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" Info *HSymID__tf();

static inline void *make(Vec *v) {
    v->b = 0; v->e = 0; v->c = 0;
    void *p = func_00326750(0x3C, 4, "RefCounter");
    hCode__structor_0(p, v);
    return p;
}
static inline void range(int *first, int *last, T *t) {
    t->it = first;
    for (int *q = first; q != last; ++q) ;
}
static inline void destroy(Vec *v, T *t) {
    range(v->b, v->e, t);
    int *bb = v->b;
    int cnt = v->c - bb;
    if (bb) func_00326798(bb, cnt * 4, 4, HSymID__tf()->name);
}
static inline void read(char *self, void *arg) {
    H h0;
    Vec v;
    T t;
    mDefine__read(self, arg);
    void **slot = (void **)(self + 0xC);
    void **ph = &t.h1;
    t.h1 = make(&v);
    func_00309348(&h0, ph);
    if (slot != (void **)&h0) {
        void *nv = h0.p;
        if (nv != 0) func_003285A8(nv);
        void *ov = *slot;
        if (ov != 0) func_003285F8(ov);
        *slot = nv;
    }
    func_002F4210(&h0, 2);
    destroy(&v, &t);
    func_002F4A10(*slot, arg);
}

extern "C" void mFunctionDefine__read(char *self, void *arg) { read(self, arg); }
