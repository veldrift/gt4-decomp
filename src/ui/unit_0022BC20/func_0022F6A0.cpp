struct Vec { int a; char *b; char *e; char *c; };
struct P2 { char *b; char *e; };
struct Obj { char pad[4]; char *vtbl; };
struct VE { short delta; short idx; void (*fn)(void *, void *); };
extern "C" void mUpdateContext__Sync(int) ;
extern "C" void func_0022F080(void *, void *) throw();
extern "C" void func_0022F178(void *, void *) throw();
extern "C" void func_0022F248(char *, int) throw();
extern "C" void func_0022F2F8(char *, int) throw();
extern "C" void func_0022F3A8(char *, int) throw();
extern "C" void IfRootEvent__structor_0(void *, void *) throw();
extern "C" void func_00233D18(void *);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_00327970(void);
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" void *func_005A47D4(void *, const void *, unsigned) throw();
extern "C" const char **func_005DB330(void);

static inline char *cp(char *first, char *last, char *dest) {
    int n = last - first;
    func_005A47D4(dest, first, n);
    return dest + n;
}

extern "C" void func_0022F6A0(char *self) {
    Vec v;
    Vec *src = (Vec *)(self + 0x14);
    int h = (int)(self + 0x48);
    int saved;
    *(int *)(self + 0x6DC) = 0;
    saved = *(int *)(self + 0x6E0);
    *(int *)(self + 0x6E0) = 1;
    mUpdateContext__Sync(2);
    func_00576788(h);
    v.b = 0;
    v.e = 0;
    v.c = 0;
    int n = (src->e - src->b) >> 2;
    char *p = (char *)func_00326750(n * 4, 4, *func_005DB330());
    char *pad[4];
    char *tmp;
    (void)&tmp; (void)&pad;
    v.b = p;
    v.e = p;
    tmp = p;
    char *cap = p + n * 4;
    v.c = cap;
    v.e = cp(src->b, src->e, p);
    func_005767C0(h);
    IfRootEvent__structor_0(self, &v);
    for (char **it = (char **)v.b; it != (char **)v.e; it++)
        func_00233D18(*it);
    mUpdateContext__Sync(2);
    for (char **it = (char **)v.b; it != (char **)v.e; it++) {
        char *o = *it;
        VE *e = (VE *)(*(char **)(o + 4) + 0x2D8);
        e->fn(o + e->delta, self);
    }
    func_0022F080(self, 0);
    func_0022F178(self, 0);
    func_0022F248(self, 0);
    func_0022F2F8(self, 0);
    func_0022F3A8(self, 0);
    func_00327970();
    *(int *)(self + 0x6E0) = saved;
    *(int *)(self + 0x6DC) = 1;
    char *b = v.b;
    int cnt = (v.c - b) >> 2;
    tmp = b;
    if (b)
        func_00326798(b, cnt * 4, 4, *func_005DB330());
}
