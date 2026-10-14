/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[12];
};

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Callee {
    char pad0[4];
    char *vtbl;
};

struct Vec {
    char pad0[4];
    s32 *begin;
    s32 *end;
};

struct mFunctionEvent {
    char pad0[4];
    char *vtbl;
    char pad8[8];
    s32 unk10;
    s32 unk14;
    char pad18[8];
    Callee *obj;
    Vec vec;
};

extern char D_00697778[];
extern char D_00697780[];
extern char D_00697798[];
extern char D_006977A8[];
extern char D_006977B0[];

extern "C" void func_005D4AD8(const char *fmt, ...);
extern "C" void hModule__getName(s32 arg0);
extern "C" s32 func_0028EA08(void *arg0);
extern "C" s32 func_0028EA18(void *arg0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_0030BB18(void *arg0);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

typedef s32 (*Fn1)(void *);
typedef void (*Fn2)(void *, void *, s32);
typedef void (*FnS)(Str *, void *);
typedef void (*FnV)(void *, void *, s32, s32 *);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_006977A8;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" s32 mFunctionEvent__dispatchEvent(mFunctionEvent *self) {
    Str s;
    Callee **h = &self->obj;
    func_005D4AD8(D_00697778);
    {
        VEntry *e = (VEntry *)(self->vtbl + 0x50);
        s32 r = ((Fn1)e->fn)((char *)self + e->delta);
        func_005D4AD8(D_00697780, ((s32 (*)(s32))hModule__getName)(r), self->unk14, self->unk10);
    }
    {
        s32 a = func_0028EA08(self);
        s32 b = func_0028EA18(self);
        VEntry *e = (VEntry *)(self->vtbl + 0x198);
        ((Fn2)e->fn)((char *)self + e->delta, (void *)a, b);
    }
    {
        Callee *o = *h;
        VEntry *e = (VEntry *)(o->vtbl + 0x18);
        ((FnS)e->fn)(&s, (char *)o + e->delta);
    }
    func_005D4AD8(D_00697798, c_str(&s));
    release(&s);
    func_0030BB18(&s);
    {
        Vec *v = &self->vec;
        Callee *o = *h;
        s32 *b = v->begin;
        s32 n = v->end - b;
        VEntry *e = (VEntry *)(o->vtbl + 0xA8);
        ((FnV)e->fn)((char *)o + e->delta, &s, n, b);
    }
    func_005D4AD8(D_006977B0);
    func_00309378(&s, 2);
    return 1;
}
