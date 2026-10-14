/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab();
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str() {}
    Str(const Str &);
    ~Str();
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, char *);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;

extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005CB368(Str *s, s32 pos, s32 n1, s32 n2, char c);

inline char *Rep::grab() {
    if (sel != 0) return func_005C2560(this);
    s32 n = ref + 1;
    ref = n;
    return data();
}

static inline void release(Str *s) {
    Rep *q = s->rep();
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

inline Str::Str(const Str &src) { p = src.rep()->grab(); }
inline Str::~Str() { release(this); }

static inline s32 get(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x1B8);
    return ((s32 (*)(void *))e->fn)((char *)o + e->delta);
}

extern "C" Str hIO__sget(VObj *arg1) {
    Str s;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s.p = d;
    }
    VEntry *e = (VEntry *)((char *)arg1->vtbl + 0x1A0);
    if (((s32 (*)(void *))e->fn)((char *)arg1 + e->delta) != 0) return s;
    s32 c;
    while ((c = get(arg1)) != -1) {
        if (c == 10) return s;
        func_005CB368(&s, *(s32 *)(s.p - 0x10), 0, 1, (char)c);
    }
    return s;
}
