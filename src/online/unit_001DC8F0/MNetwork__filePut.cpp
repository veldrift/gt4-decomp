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
    char pad[0xC];
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" void *func_001F7C68(void *);
extern "C" void func_001F7CB8(void *, void *, const char *, s32, s32, s32, s32, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" s32 hArray__size(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" s32 func_002FC840(void *, void *);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = ((Rep **)s)[0] - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

struct Parsed { int error, alt, len, altlen; char *data; char pad[12]; };
extern "C" void func_004AE230(Parsed *, const char *, int);
extern "C" int func_001F7720(void *, const char *, int, int);
extern "C" int func_001F77A0(void *, const char *, int);
extern "C" int func_001F7810(void *);
extern "C" void free(void *) throw();
static inline void set_result(void **dst, Str *t, int value) {
    func_002FE278(t, value);
    if ((void *)dst != (void *)t) {
        void *p = t->p;
        if (p) func_003285A8(p);
        if (*dst) func_003285F8(*dst);
        *dst = p;
    }
    func_002FC870(t, 2);
}
extern "C" void MNetwork__filePut(void **arg0, void *ctx, int n, VObj **args) {
    Str h;
    if (n > 0) {
        Str t;
        Parsed parsed;
        func_001DC650(&h, ctx);
        Str *pt = &t;
        vcall18(pt, args[0]);
        const char *name = c_str(pt);
        str_release(pt);
        int own = 0;
        int mode = 1;
        const char *data;
        int len;
        if (n >= 2) {
            vcall18(pt, args[1]);
            data = c_str(pt);
            len = (((Rep **)pt)[0] - 1)->len + 1;
            str_release(pt);
        } else {
            Parsed *pp = &parsed;
            func_004AE230(pp, name, 0);
            if (pp->error) {
                set_result(arg0, pt, 0);
                func_001DC5F8(&h, 2);
                return;
            }
            own = 1;
            mode = 0;
            data = parsed.data;
            len = parsed.alt ? parsed.altlen : parsed.len;
        }
        if (!func_001F7720(h.p, name, len, mode)) {
            set_result(arg0, pt, 0);
            if (own) free((void *)data);
            func_001DC5F8(&h, 2);
            return;
        }
        if (!func_001F77A0(h.p, data, len)) {
            set_result(arg0, pt, 0);
            if (own) free((void *)data);
            func_001DC5F8(&h, 2);
            return;
        }
        if (own) free((void *)data);
        if (!func_001F7810(h.p)) {
            set_result(arg0, pt, 0);
            func_001DC5F8(&h, 2);
            return;
        }
        set_result(arg0, pt, 1);
        func_001DC5F8(&h, 2);
    }
}
