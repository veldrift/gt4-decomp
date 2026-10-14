/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result { int value; };
struct Pair { int a; int b; };
struct VEI { short delta; short index; void (*fn)(void *, int, Pair *, float); };
struct VEF { short delta; short index; void (*fn)(void *, float); };
struct VE0 { short delta; short index; int (*fn)(void *); };
struct VE3 { short delta; short index; int (*fn)(void *, char *, int); };
struct Vec { int x; char *b; char *e; char *c; };
struct Loc { char *vtbl; int a; char pad[8]; Vec v; char pad2[0x10]; };
struct Self { char p[0x4C]; char *tbl; };
struct Hh { char *tbl; };
extern "C" char D_00661718[];
extern "C" char D_0065CE00[];
extern "C" Result func_001CD410(Self *, int, Vec *) throw();
extern "C" int func_001D4E60(char *, int, int, int, float, float);
extern "C" int func_0044D1B8(Hh *, char *, int);
extern "C" Hh *func_0044D2E0(int);
extern "C" void func_0044D320(Hh *);
extern "C" void free(char *) throw();
static inline int status(const Result *const x) { return x->value; }
static inline void progress(Loc *const self, float value) {
    VEF *e = (VEF *)(self->vtbl + 0x10);
    e->fn((char *)self + e->delta, value);
}
static inline void fin(Loc *l, char *vt2) {
    if (l->v.b) free(l->v.b);
    l->vtbl = vt2;
}
extern "C" int func_001CFFF8(Self *self, int arg1, Pair *p, int arg3) {
    Loc loc;
    loc.vtbl = D_00661718;
    loc.a = arg3;
    char *vt2 = D_0065CE00;
    VEI *e1 = (VEI *)(D_00661718 + 0x10);
    e1->fn((char *)&loc + e1->delta, arg1, p, 0.0f);
    progress(&loc, 0.98f);
    loc.v.b = 0;
    loc.v.e = 0;
    loc.v.c = 0;
    Result result = func_001CD410(self, arg1, &loc.v);
    int r = result.value;
    if (status(&result)) {
        fin(&loc, vt2);
        return r;
    }
    char *s0 = loc.v.b;
    if (func_001D4E60(s0, loc.v.e - s0, 0, 0, 0x1.d67df0p-3f, 0x1.644622p-1f) < 0) {
        fin(&loc, vt2);
        return 2;
    }
    int id = p->b;
    if (id == 0) {
        VE0 *e0 = (VE0 *)(self->tbl + 0x100);
        id = e0->fn((char *)self + e0->delta);
    }
    Hh *h = func_0044D2E0(id);
    progress(&loc, 1.0f);
    VE3 *e3 = (VE3 *)(h->tbl + 0x30);
    if (e3->fn((char *)h + e3->delta, s0 + 8, p->a) >= 2) {
        func_0044D320(h);
        fin(&loc, vt2);
        return 2;
    }
    int rr = func_0044D1B8(h, s0 + 8, p->a);
    func_0044D320(h);
    if (rr == 0) {
        fin(&loc, vt2);
        return 2;
    }
    progress(&loc, 1.0f);
    fin(&loc, vt2);
    return 0;
}
