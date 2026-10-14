typedef int s32;
typedef unsigned char u8;

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
};

union U {
    Str s;
    s32 h[4];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

struct Rec {
    char pad[0x11];
    u8 flag;
    char pad2[0xE];
};

extern char D_00693270[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_00447C78(const char *s);
extern "C" bool func_00447F48(s32 id, Rec *out);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00693270;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" void MCourseData__GetMaxCarNum(s32 *arg0, s32 arg1, VObj **arg2) {
    if (arg1 > 0) {
        U u;
        Rec rec;
        s32 s3;
        bool ok;
        s32 newVal;
        s32 oldVal;

        vcall(&u, *arg2);
        s3 = func_00447C78(c_str(&u.s));
        release(&u.s);
        ok = func_00447F48(s3, &rec);
        func_002FE278(&u, ok ? rec.flag : 0);
        if (arg0 != u.h) {
            newVal = u.h[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(&u, 2);
    }
}
