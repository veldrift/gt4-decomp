/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };

extern "C" void func_002EAC30(Ref *, void *, int) throw();
extern "C" void func_002EAEF0(void *, Ref *) throw();
extern "C" int func_002EB7A0(void *, int, Ref *) throw();
extern "C" void func_00304188(void *, const int &);
extern "C" void func_003041A0(void *, Ref *);
extern "C" void func_003041B8(Ref *, int);
extern "C" void func_00306E00(Ref *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_003285A8(q);
        if (d->p) func_003285F8(d->p);
        d->p = q;
    }
}

extern "C" void *func_002EC260(void *a0, void *a1, int a2) {
    Ref r0;
    Ref u;
    func_002EAC30(&r0, a1, a2);
    if (r0.p != 0 || (func_00306E00(&u, a2), assign(&r0, &u), func_003041B8(&u, 2), func_002EAEF0(a1, &r0), func_002EB7A0(a1, a2, &r0) != 0)) {
        func_003041A0(a0, &r0);
        func_003041B8(&r0, 2);
    } else {
        func_00304188(a0, 0);
        func_003041B8(&r0, 2);
    }
    return a0;
}
