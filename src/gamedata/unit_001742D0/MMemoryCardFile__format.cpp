/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };
struct Cb { void *vtbl; void *fn; char *p; int pad; };

extern char D_0065CDE0[];
extern char D_0065CE00[];

extern "C" void func_00179280(void *arg0, int arg1);
extern "C" void func_001792D8(void *arg0, void *arg1);
extern "C" int func_001CC848(void *a, void *b);
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

extern "C" void MMemoryCardFile__format(Ref *out, void *a1, int count, void *a3) {
    if (count > 0) {
        Ref b;
        Cb c;
        Ref r;
        func_001792D8(&b, a3);
        Cb *pc = &c;
        void *fnp = (void *)func_001742F0;
        char *t = b.p + 0x10;
        pc->vtbl = D_0065CDE0;
        c.fn = fnp;
        c.p = t;
        func_002FE278(&r, func_001CC848(*(void **)(b.p + 0x1C), pc) != 0);
        assign(out, &r);
        func_002FC870(&r, 2);
        pc->vtbl = D_0065CE00;
        func_00179280(&b, 2);
    } else {
        Ref r;
        func_002FE278(&r, 0);
        assign(out, &r);
        func_002FC870(&r, 2);
    }
}
