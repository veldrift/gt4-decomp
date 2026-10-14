/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Stat { char pad[0x10]; int size; char pad2[0x2c]; };
struct Obj0 { char pad[16]; };
extern char D_00697A98[];
extern "C" void func_0048F270(Obj0 *);
extern "C" void func_0048F2B0(Obj0 *, int);
extern "C" void func_0048F3C0(Obj0 *, void *);
extern "C" int func_0054A530(int);
extern "C" int func_0054B1A8(int, const char *, Stat *, int, int);
extern "C" void func_0054B698(int, const char *, void *, int, int);
extern "C" int func_0054C2D0(int);
extern "C" void free(int) throw();
extern "C" int func_00575E60(int, int);
extern "C" void func_00213C88(void *, Str *, Obj0 *) throw();

static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_00697A98;
    s->p[n] = 0;
    return s->p;
}

extern "C" void mUpdateContextPS2__virtual_54(void *self, Str *name) {
    Obj0 o;
    Stat st;
    func_0048F270(&o);
    const char *path = c_str(name);
    if (func_0054B1A8(0, path, &st, 0, 1) != 0 || func_0054A530(0) != 0 || func_0054C2D0(0) != 1) {
        func_0048F2B0(&o, 2);
        return;
    }
    int sz = st.size;
    sz = (sz + 0x3F) & ~0x3F;
    void *buf = (void *)func_00575E60(0x40, sz);
    func_0054B698(0, path, buf, 0, sz);
    if (func_0054A530(0) != 0) {
        free((int)buf);
        func_0048F2B0(&o, 2);
        return;
    }
    func_0048F3C0(&o, buf);
    func_00213C88(self, name, &o);
    func_0048F2B0(&o, 2);
}
