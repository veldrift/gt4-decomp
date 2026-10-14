typedef int s32;

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

union U {
    Str s;
    s32 h[4];
};

struct Handle {
    void *p;
    char pad[0xC];
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

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void *func_001FA370(void *arg0, const char *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_006959D8;
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

extern "C" void MNetwork__billingPurchaseProduct(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 > 0) {
        U u;
        Handle h;
        Handle *ph;
        s32 spare[4];
        Str s;
        void *hp;
        s32 newVal;
        s32 oldVal;

        ph = &h;
        func_001DC650(ph, arg1);
        hp = ph->p;
        vcall(&s, *arg3);
        func_002FE278(&u, func_001FA370(hp, c_str(&s)) != 0);
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
        release(&s);
        func_001DC5F8(ph, 2);
    }
}
