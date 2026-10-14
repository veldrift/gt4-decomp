struct Ref { char *p; int pad[3]; };
struct Obj {
    char pad0[0x2BC];
    int f2BC;
    Ref r2C0;
};
extern "C" void mTextFace__virtual_68(void *);
extern "C" void func_0021B5A0(Ref *, const int &);
extern "C" void func_0021B5D0(Ref *, int);
extern "C" void func_002106E0(Ref *, const int &);
extern "C" void func_00210710(Ref *, int);
extern "C" void func_0021A828(void *, void *);
extern "C" void func_0021A858(void *, void *);
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

extern "C" void mModelFace__virtual_68(Obj *o) {
    char *c = (char *)o;
    Ref t;
    mTextFace__virtual_68(o);
    o->f2BC = 0;
    func_0021B5A0(&t, 0);
    assign((Ref *)(c + 0x2C0), &t);
    func_0021B5D0(&t, 2);
    func_0021B5A0(&t, 0);
    assign((Ref *)(c + 0x2C4), &t);
    func_0021B5D0(&t, 2);
    *(int *)(c + 0x2CC) = 0;
    Ref *d = (Ref *)(c + 0x2D0);
    func_002106E0(&t, 0);
    assign(d, &t);
    func_00210710(&t, 2);
    func_002106E0(&t, 0);
    assign((Ref *)(c + 0x2D4), &t);
    func_00210710(&t, 2);
    func_0021A828(c + 0xA0, c + 0x2E4);
    func_0021A858(c + 0xA0, c + 0x2F0);
}
