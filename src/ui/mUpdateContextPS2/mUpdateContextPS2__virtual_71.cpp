/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Obj { int a; char pad[12]; void *data; char pad2[12]; };
extern char D_00697A98[];
extern "C" void *func_002147D8(void *, Str *, int *) throw();
extern "C" void func_0021B310(void *, int *);
extern "C" void func_0021B328(void *, Obj *);
extern "C" void func_0021B340(Obj *, int);
extern "C" void func_0021B480(Obj *);
extern "C" void func_0021B4D8(int, void *, int);
extern "C" void func_004AE230(Obj *, const char *, int);

static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_00697A98;
    s->p[n] = 0;
    return s->p;
}

extern "C" void *mUpdateContextPS2__virtual_71(void *ret, void *self, Str *name, int flag) {
    int sp0;
    Obj o;
    void *p;
    int z1;
    int z2;
    if (flag) {
        Obj *po = &o;
        func_004AE230(po, c_str(name), 1);
        if (__builtin_expect(po->a, 0)) {
            z1 = 0;
            func_0021B310(ret, &z1);
            return ret;
        } else {
            p = o.data;
            sp0 = 1;
        }
    } else {
        p = func_002147D8(self, name, &sp0);
        if (p == 0) {
            z2 = 0;
            func_0021B310(ret, &z2);
            return ret;
        }
    }
    Obj *out = &o;
    func_0021B480(out);
    func_0021B4D8(out->a, p, sp0);
    func_0021B328(ret, out);
    func_0021B340(out, 2);
    return ret;
}
