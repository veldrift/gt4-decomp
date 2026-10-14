/* compiler: ee-gcc2.96-nogcse */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct TypeInfo { const char *name; };
struct VEntry { short delta, index; void (*fn)(Str *, void *); };
struct Obj { int pad; char *vtbl; };
extern char D_0069B728[];
extern "C" void *func_002A0D78(void *, void *) throw();
extern "C" void func_002A0D20(void *, int) throw();
extern "C" void func_002A36F0(int, const char *, int);
extern "C" TypeInfo *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline Rep *rep(Str *s) { return (Rep *)(s->p - 16); }
static inline int length(Str *s) { return rep(s)->len; }
static inline char *data(Rep *r) { return (char *)(r + 1); }
static inline void terminate(Str *s) { data(rep(s))[length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (length(s) == 0) return D_0069B728;
    terminate(s);
    return data(rep(s));
}
extern "C" void MImageFace__set_image_chunk(void *ret, void *ctx, int n, Obj **args) {
    if (n > 0) {
        Str s;
        int h[4];
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x18);
        e->fn(&s, (char *)o + e->delta);
        int *ph = h;
        func_002A0D78(ph, ctx);
        int obj = *ph;
        const char *name = c_str(&s);
        func_002A36F0(obj, name, length(&s));
        func_002A0D20(ph, 2);
        Rep *q = (Rep *)(*(int *)&s.p - 0x10);
        if (--q->ref == 0) {
            int cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
