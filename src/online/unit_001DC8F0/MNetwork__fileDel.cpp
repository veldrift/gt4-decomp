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

extern "C" void MNetwork__fileDel(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Str sp0;
    if (arg2 > 0) {
        Str t;
        Str h;
        Str *pt;
        const char *c;
        func_001DC650(&sp0, arg1);
        pt = &t;
        vcall18(pt, *arg3);
        c = c_str(pt);
        str_release(pt);
        func_001F7CB8(pt, sp0.p, c, 0, 100000000, -1, 0, 1);
        if (pt->p == 0 || hArray__size(pt->p) == 0) {
            Str *ph = &h;
            func_002FE278(ph, 0);
            if ((void *)arg0 != (void *)ph) {
                void *p = ph->p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_002FC870(ph, 2);
            func_002ED5C0(pt, 2);
            func_001DC5F8(&sp0, 2);
        } else {
            Str *ph;
            s32 nz = func_001F7C68(sp0.p) != 0;
            ph = &h;
            func_002FE278(ph, nz);
            if ((void *)arg0 != (void *)ph) {
                void *p = ph->p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_002FC870(ph, 2);
            func_002ED5C0(pt, 2);
            func_001DC5F8(&sp0, 2);
        }
    }
}
