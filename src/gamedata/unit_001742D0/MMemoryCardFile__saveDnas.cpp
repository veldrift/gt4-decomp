/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };
struct Cb { void *vtbl; void *fn; char *p; int pad; };
struct Pair { int a; int b; int pad[2]; };
struct VE { short delta; short idx; int (*fn)(void *, void *, void *, void *); };
struct Svc { char pad0[0x10]; char *obj; };

extern char D_0065CDE0[];
extern char D_0065CE00[];

extern "C" void func_001740F0(void *arg0, int arg1) throw();
extern "C" void func_00174148(void *arg0, void *arg1) throw();
extern "C" void func_00179280(void *arg0, int arg1);
extern "C" void func_001792D8(void *arg0, void *arg1);
extern "C" void func_001DAED0(void *arg0, int arg1);
extern "C" void func_001DAF28(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" void func_001742F0(void *);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_003285A8(q);
        if (d->p) func_003285F8(d->p);
        d->p = q;
    }
}

extern "C" void MMemoryCardFile__saveDnas(Ref *out, void *a1, int count, char *a3) {
    if (count >= 3) {
        Ref a;
        Ref b;
        Ref d;
        Ref e;
        Cb c;
        Pair f;
        Ref r;
        func_00174148(&a, a1);
        Ref *pb = &b;
        func_001792D8(pb, a3);
        Ref *pd = &d;
        func_00312370(pd, a3 + 4);
        Ref *pe = &e;
        func_001DAF28(pe, a3 + 8);
        Cb *pc = &c;
        void *fnp = (void *)func_001742F0;
        char *t = pb->p + 0x10;
        pc->vtbl = D_0065CDE0;
        c.fn = fnp;
        c.p = t;
        Pair *pf = &f;
        char *eo = pe->p + 0x10;
        int fa = *(int *)(eo + 4);
        int fb = *(int *)(eo + 8);
        pf->a = fa;
        f.b = fb;
        char *obj = *(char **)(a.p + 0x10);
        VE *ve = (VE *)(*(char **)(obj + 0x4C) + 0x18);
        func_002FE278(&r, ve->fn(obj + ve->delta, *(void **)(pb->p + 0x1C), pf, pc) == 0);
        assign(out, &r);
        func_002FC870(&r, 2);
        pc->vtbl = D_0065CE00;
        func_001DAED0(pe, 2);
        func_00312318(pd, 2);
        func_00179280(pb, 2);
        func_001740F0(&a, 2);
    } else {
        Ref r;
        func_002FE278(&r, 0);
        assign(out, &r);
        func_002FC870(&r, 2);
    }
}
