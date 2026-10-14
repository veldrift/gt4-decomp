/* compiler: ee-gcc2.96-no-strict-aliasing */
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

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct Obj {
    char pad0[0x9C];
    s32 flags;
};

extern Rep D_00659FA8;

extern "C" s32 func_00265D00(Obj *arg0);
extern "C" void *func_002FA120(void *arg0);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_003069F8(Obj *obj, void *h, s32 *val);
extern "C" void func_0030BB18(void *h);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_005DB110(const char *fmt, const char *file, s32 line);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

struct MethodHandle {
    s32 p;
    s32 pad[3];
    MethodHandle() { func_002FA120(this); }
    ~MethodHandle() { func_002F9B38(this, 2); }
};

static inline s32 vcall10(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

#define DESTROY_ARGS()                          \
    {                                           \
        Value *q = args + 2;                    \
        while (args != q) {                     \
            --q;                                \
            func_00309378(q, 2);                \
        }                                       \
    }

static inline void set_arg(Value *dst, s32 *p0, s32 *tv) {
    s32 newVal;
    s32 oldVal;
    func_00309348(p0, tv);
    if (dst != (Value *)p0) {
        newVal = *p0;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = dst->p;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        dst->p = newVal;
    }
    func_00309378(p0, 2);
}
#define SET_ARG(i, tv, v) tv = (v); set_arg(&args[i], tmp, &tv);

extern "C" void *func_00235C00(void *);
extern "C" void func_002350C8(void *, unsigned, void *, void *) throw();
extern "C" void mPhotoMapWindow__virtual_90(void *, int);
extern "C" void mRootWindow__virtual_90(Obj *self, s32 arg1) {
    if (func_00235C00(self) != 0) {
        func_002350C8((char*)self + 0xCC, 0, func_00235C00(self), self);
    }
    if (func_00265D00(self) != 0) {
        MethodHandle h;
        s32 ret[4];
        Str s;
        s32 *pv;
        pv = ret;
        {
            Str *ps = &s;
            const char *src = "onFinalize";
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
            *pv = HSymID__GetID(ps);
            func_003069F8(self, &h, pv);
            {
                Rep *q = (Rep *)(ps->p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        }
        /* The branch hint gives reorg the original's delay-slot choice (it fills the
           h.p == 0 branch from its target). */
        if (h.p) {
            func_0030BB18(pv);
            {
                Value args[2];
                s32 tmp[4];
                s32 tv1;


                SET_ARG(0, tv1, arg1)

                vcall20((VObj *)h.p, pv, 1, args);
                DESTROY_ARGS();
                func_00309378(pv, 2);
            }
        }
    }
    mPhotoMapWindow__virtual_90(self, arg1);
}
