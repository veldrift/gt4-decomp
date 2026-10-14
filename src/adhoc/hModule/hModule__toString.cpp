/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; char pad[12]; };
struct Rep { int len, cap, ref, sel; };
struct Type { const char *name; };
struct Entry { short delta, index; int (*fn)(void *); };
struct Obj { int x; char *vt; };
extern char D_0069DC50[], D_0069DC58[], D_0069DC60[], D_0069DC68[], D_0069DC70[], D_0069DC78[];
extern "C" const char *hModule__getName(int) throw();
extern "C" void func_003056D0(Str *, Obj *) throw();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int func_003284E8(Obj *);
extern "C" void func_0032B5C0(Str *);
extern "C" Str *func_0032B658(Str *, Str *);
extern "C" Str *func_0032B6D8(Str *, int);
extern "C" Str *func_0032B808(Str *, const char *);
extern "C" Str *func_0032B860(Str *, Obj *);
extern "C" Str *func_0032B8C0(Str *);
extern "C" Type *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
static inline int call(Obj *o, int off) {
    Entry *e = (Entry *)(o->vt + off);
    return e->fn((char *)o + e->delta);
}
extern "C" Str *hModule__toString(Str *out, Obj *self) {
    Str s;
    func_0032B5C0(&s);
    int base = call(self, 0x50);
    {
        Str t;
        Str *b = func_0032B808(func_0032B808(func_0032B808(&s, D_0069DC50), hModule__getName(base)), D_0069DC58);
        Str *pt = &t;
        func_003056D0(pt, self);
        func_0032B808(func_0032B658(b, pt), D_0069DC60);
        release(pt);
    }
    func_0032B860(func_0032B808(&s, D_0069DC68), self);
    {
        Str *b = func_0032B808(&s, D_0069DC70);
        func_0032B6D8(b, func_003284E8(self));
    }
    {
        Str *b = func_0032B808(&s, D_0069DC78);
        func_0032B6D8(b, call(self, 0x40));
    }
    func_0032B808(&s, D_0069DC60);
    {
        char *sp = func_0032B8C0(&s)->p;
        Rep *r = (Rep *)(sp - 16);
        char *d;
        if (r->sel != 0) d = func_005C2560(r);
        else { d = sp; r->ref++; }
        out->p = d;
    }
    release(&s);
    return out;
}
