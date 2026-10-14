/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int x; char *b; char *e; };
struct VEI { short delta; short index; void (*fn)(void *, int, Vec *, float); };
struct VEF { short delta; short index; void (*fn)(void *, float); };
struct VE1 { short delta; short index; int (*fn)(void *, int); };
struct VEG { short delta; short index; int (*fn)(void *, char *); };
struct Self { char p[0x4C]; char *tbl; };
struct Loc { char *vtbl; int a;  };
struct G { char *tbl; };
extern "C" char D_00661718[];
extern "C" char D_0065CE00[];
extern "C" G *D_00622F4C;
struct Result { int value; };
extern "C" Result func_001CD410(Self *, int, Vec *) throw();
extern "C" int func_001D4E60(char *, int, int, int, float, float);
extern "C" void func_005A47D4(char *, char *, unsigned) throw();
extern "C" void func_005D0F50(Vec *, char *, unsigned, char *);
static inline int status(const Result *const x) { return x->value; }
static inline void init(Result *const x, int value) { x->value = value; }
static inline char *begin(Vec *v) { return v->b; }
static inline char *end(Vec *v) { return v->e; }
static inline unsigned size(Vec *v) { return end(v)-begin(v); }
static inline void erase(Vec *v, char *first, char *last) {
    func_005A47D4(first, last, end(v)-last);
    v->e -= last-first;
}
static inline void resize(Vec *v, unsigned n, const char &x) {
    if (n < size(v)) erase(v, begin(v)+n, end(v));
    else func_005D0F50(v, end(v), n-size(v), (char *)&x);
}
extern "C" int func_001CDAC8(Self *self, int arg1, Vec *v, int arg3) {
    Loc loc;
    char *vt2 = D_0065CE00;
    loc.a = arg3;
    loc.vtbl = D_00661718;
    VEF *e1 = (VEF *)(D_00661718 + 0x10);
    e1->fn((char *)&loc + e1->delta, 0.05f);
    VE1 *e0 = (VE1 *)(self->tbl + 0x38);
    e0->fn((char *)self + e0->delta, arg1);
    VEF *e = (VEF *)(loc.vtbl + 0x10);
    e->fn((char *)&loc + e->delta, 0.98f);
    Result result = func_001CD410(self, arg1, v);
    int r = status(&result);
    if (r) {
        loc.vtbl = vt2;
        return result.value;
    }
    int se0 = (int)v->e;
    char *s1 = v->b;
    int n = se0 - (int)s1;
    int ret;
    if (n == 0) { loc.vtbl = vt2; return 2; }
    {
        int s0 = func_001D4E60(s1, n, 0, 0, 0x1.161910p-3f, 0x1.4f49cep-1f);
        if (s0 < 0) { loc.vtbl = vt2; return 2; }
        {
            func_005A47D4(v->b, s1 + 8, s0);
            resize(v, s0, char());
            VEF *e3 = (VEF *)(loc.vtbl + 0x10);
            e3->fn((char *)&loc + e3->delta, 1.0f);
            G *g = D_00622F4C;
            VEG *eg = (VEG *)(g->tbl + 0x18);
            if (eg->fn((char *)g + eg->delta, v->b) == 0) {
                loc.vtbl = D_0065CE00; return 2;
            }
            loc.vtbl = D_0065CE00;
            return 0;
        }
    }
    loc.vtbl = vt2;
    return 2;
}
