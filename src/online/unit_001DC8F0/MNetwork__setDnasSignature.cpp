/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct Block { int v[8]; };
struct Info { const char *name; };
struct VEntry { short delta, index; void (*fn)(Str *, void *); };
struct Obj { int unused; char *vt; };
extern char D_006959D8[];
extern Block D_008297E0;
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
extern "C" void MNetwork__setDnasSignature(void *arg0, void *arg1, int arg2, Obj **args) {
    Str s;
    Obj *o = *args;
    VEntry *e = (VEntry *)(o->vt + 0x18);
    e->fn(&s, (char *)o + e->delta);
    const char *name = c_str(&s);
    Rep *q = (Rep *)(*(int *)&s.p - 0x10);
    if (--q->ref == 0) {
        int cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
    D_008297E0 = *(const Block *)name;
}
