struct N { int v[3]; };
struct S { void *p; N n; };
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_0030BB18(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" int func_0032A228(void *, void *, const char *, int, void *);
extern "C" void func_005A6AB0(void *, const char *, void *) throw();

extern "C" void func_00435FD0(void *arg0, void *arg1, void *arg2) {
    S a;
    S b;
    func_0030BB18(&a);
    S *pb = &b;
    func_002FE278(pb, arg2);
    if (&a != pb) {
        void *t = pb->p;
        if (t) func_003285A8(t);
        if (a.p) func_003285F8(a.p);
        a.p = t;
    }
    func_002FC870(pb, 2);
    if (func_0032A228(arg0, arg1, "getUsingLanguage", 1, &a)) {
    } else {
        func_005A6AB0(arg0, "JP", arg1);
    }
    if ((void *)&a != (void *)&a.n)
        func_00309378(&a, 2);
}
