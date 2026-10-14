struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct Block { int v[8]; };
struct Info { const char *name; };
struct VEntry { short delta, index; void (*fn)(Str *, void *); };
struct Obj { int unused; char *vt; };
extern char D_006959D8[];

extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline Rep *rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *data(Rep *r) { return (char *)(r + 1); }
static inline const char *c_str(Str *s) {
    int len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006959D8;
    s->p[len] = 0;
    return data(rep(s));
}
static inline void release(Str *s) {
    Rep *q = (Rep *)s->p - 1;
    if (--q->ref == 0) {
        int cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}
struct Target { char pad[0x1B4]; int value; };
extern "C" int func_0048ED30(const char *);
extern "C" void func_001DC650(void *, void *) throw();
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void MNetwork__set_language(void *arg0, void *arg1, int n, Obj **args) {
    if (n > 0) {
        Str s;
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vt + 0x18);
        e->fn(&s, (char *)o + e->delta);
        const char *name = c_str(&s);
        release(&s);
        int value = func_0048ED30(name);
        func_001DC650(&s, arg1);
        ((Target *)s.p)->value = value;
        func_001DC5F8(&s, 2);
    }
}
