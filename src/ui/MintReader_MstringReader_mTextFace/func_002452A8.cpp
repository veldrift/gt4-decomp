/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[0x104]; void *p104; int p108, a, b; };
struct Info { const char *name; };
extern char D_00699158[];
extern "C" int func_00247448(void *, Obj *);
extern "C" Str *func_002457E8(Str *, Obj *, int, int);
extern "C" Str *func_002B74B0(Str *, void *);
extern "C" void func_00490B98(int, float *, float *, const char *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_00699158;
    s->p[n] = 0;
    return s->p;
}
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
extern "C" void func_002452A8(Obj *o, float *a, float *b) {
    int face = func_00247448((char *)o + 0xA0, o);
    if (o->a >= 0 && o->b >= 0) {
        Str s;
        func_002457E8(&s, o, o->a, o->b);
        func_00490B98(face, a, b, c_str(&s));
        release(&s);
    } else {
        Str s;
        func_002B74B0(&s, o->p104);
        func_00490B98(face, a, b, c_str(&s));
        release(&s);
    }
}
