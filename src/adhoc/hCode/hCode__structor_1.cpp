/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Name { const char *name; };
struct T { T *p; };
struct Vec { s32 pad0; T *start; T *finish; T *eos; };
struct Self {
    char pad0[4]; void *vt;
    char pad8[8]; Vec v2;
    s32 f20; char pad24[8]; Vec v1;
};

extern void *hCode__vtable;
extern "C" void func_002F4988(void *);
extern "C" void func_003286B8(void *);
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" Name *HSymID__tf(void);
extern "C" Name *func_005EE2B0(void);

static inline T *value_type(T *const *) { return 0; }
static inline void destroy_aux(T *, T *, T *) {}
static inline void destroy1(T *first, T *last) { destroy_aux(first, last, value_type(&first)); }
static inline void destroy_range(T **pf, T *last) {
    for (T *p = *pf; p != last; ++p) {
    }
}

extern "C" void hCode__structor_1(Self *self, s32 flag) {
    self->vt = &hCode__vtable;
    func_002F4988(self);
    {
        Vec *v = &self->v1;
        destroy1(v->start, v->finish);
        T *st = v->start;
        s32 n = v->eos - st;
        if (st != 0) {
            func_00326798(st, n * sizeof(T), 4, func_005EE2B0()->name);
        }
    }
    if (self->f20 != 0) {
        func_003286B8((void *)self->f20);
    }
    {
        Vec *v = &self->v2;
        T *first = v->start;
        destroy_range(&first, v->finish);
        T *st = v->start;
        s32 n = v->eos - st;
        if (st != 0) {
            func_00326798(st, n * sizeof(T), 4, HSymID__tf()->name);
        }
    }
    hObject__structor_2(self, 0);
    if (flag & 1) {
        func_00326798(self, 0x3C, 4, "RefCounter");
    }
}
