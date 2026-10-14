/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; };
struct Alloc { };
struct Vec { int allocator; int *start, *finish, *end;
    Vec(const Alloc &a = Alloc()) : start(0), finish(0), end(0) {}
};
inline void *operator new(unsigned int, void *p) { return p; }
struct Obj { Str name; int line; int reader; Str other; Vec v; int a20, a24, a28, a2c; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" void func_002F7390(void *, int);
static inline void construct(Str *s) {
    Rep *r = &D_00659FA8;
    char *d = (char *)(r + 1);
    if (r->sel != 0) d = func_005C2560(r);
    else ++r->ref;
    s->p = d;
}
extern "C" int func_0020E348(Obj *o, int n) {
    volatile int tmp[4];
    Str *p = &o->other;
    construct(&o->name);
    o->line = 1;
    func_002F7390(&o->reader, n);
    construct(p);
    new (&o->v) Vec;
    o->a28 = 1;
    o->a20 = 0;
    o->a24 = 0;
    o->a2c = 0;
}
