/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Info { const char *name; };
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" char *func_005C2560(Rep *);
static inline char *data(Rep *r) { return (char *)(r+1); }
static inline char *grab(Rep *r) {
    if (r->sel) return func_005C2560(r);
    char *d = data(r);
    int n = r->ref + 1; r->ref = n;
    return d;
}
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str() {}
    Str(const Str &s) { p = grab(s.rep()); }
    ~Str() {
        Rep *r = rep();
        if (--r->ref == 0) {
            int size = r->cap + 16;
            func_00326798(r, size, 4, func_005C11A8()->name);
        }
    }
    Str &operator=(const Str &s) {
        if (&s != this) {
            this->~Str();
            p = grab(s.rep());
        }
        return *this;
    }
};
struct Obj { char pad[8]; Str s; };
extern "C" Str func_002B71D0(Obj *) throw();
extern "C" Str func_002B74B0(Obj *o) {
    Str s = func_002B71D0(o);
    if (s.rep()->len == 0) s = o->s;
    return s;
}
