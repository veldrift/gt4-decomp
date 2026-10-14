/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Obj { int a; char pad[12]; void *data; char pad2[12]; };
extern char D_00697A98[];
extern "C" void *func_002147D8(void *, Str *, int *) throw();
extern "C" void func_002106E0(void *, int *) throw();
extern "C" void func_002106F8(void *, Obj *) throw();
extern "C" void func_00273570(Obj *, int);
extern "C" void func_00273830(Obj *);
extern "C" void func_00273728(int, void *, int);
extern "C" void func_004AE230(Obj *, const char *, int);

static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_00697A98;
    s->p[n] = 0;
    return s->p;
}

extern "C" void *mUpdateContextPS2__virtual_69(void *ret, void *self, Str *name, int flag) {
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
            func_002106E0(ret, &z1);
            return ret;
        } else {
            p = o.data;
            sp0 = 1;
        }
    } else {
        p = func_002147D8(self, name, &sp0);
        if (p == 0) {
            z2 = 0;
            func_002106E0(ret, &z2);
            return ret;
        }
    }
    Obj *out = &o;
    func_00273830(out);
    func_00273728(out->a, p, sp0);
    func_002106F8(ret, out);
    func_00273570(out, 2);
    return ret;
}
