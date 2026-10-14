/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Obj { int a; char pad[12]; void *data; char pad2[12]; };
extern char D_00697A98[];
extern "C" void *func_002147D8(void *, Str *, int *) throw();
extern "C" void func_0021B5A0(void *, int *);
extern "C" void func_0021B5B8(void *, Obj *);
extern "C" void func_0021B6D0(void *);
extern "C" void func_002738D0(Obj *, int);
extern "C" void func_002739E8(Obj *);
extern "C" int func_00273C00(int, void *, int);
extern "C" void func_004AE230(Obj *, const char *, int);
extern "C" void free(void *) throw();

static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_00697A98;
    s->p[n] = 0;
    return s->p;
}

extern "C" void *mUpdateContextPS2__virtual_68(void *ret, void *self, Str *name, int flag) {
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
            func_0021B5A0(ret, &z1);
            return ret;
        } else {
            p = o.data;
            sp0 = 1;
        }
    } else {
        p = func_002147D8(self, name, &sp0);
        if (p == 0) {
            z2 = 0;
            func_0021B5A0(ret, &z2);
            return ret;
        }
    }
    Obj *out = &o;
    func_002739E8(out);
    if (func_00273C00(out->a, p, sp0) == 0) {
        free(p);
        func_0021B6D0(ret);
        func_002738D0(out, 2);
    } else {
        func_0021B5B8(ret, out);
        func_002738D0(out, 2);
    }
    return ret;
}
