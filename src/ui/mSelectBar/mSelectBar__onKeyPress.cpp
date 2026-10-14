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

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct Obj {
    char pad0[0xB0];
    s32 orientation;
    char padB4[8];
    s32 bc;
};

extern Rep D_00659FA8;
extern char D_0069CCC8[];
struct Event { char pad[0x20]; int key; };
extern "C" int func_002D7468(Obj *, int);
extern "C" int func_002D7528(Obj *, int);
extern "C" int mWidget__onKeyPress(Obj *, int, Event *);
extern "C" int func_00265D00(Obj *);
extern "C" void func_002D6D18(Obj *, int) throw();

extern "C" void *func_002FA120(void *arg0);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_002FC870(void *h, int flags);
extern "C" void func_002FE278(void *h, s32 v);
extern "C" void func_003069F8(Obj *obj, void *h, s32 *val);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_0030BB18(void *h);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

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

extern "C" int mSelectBar__onKeyPress(Obj *self, int arg1, Event *event) {
    int unknown = 0;
    int changed = 0;
    int key = event->key;
    if (self->orientation == 0) {
        if (key == 0xFF51 || key == 0xFF96) changed = func_002D7528(self, 1);
        else if (key == 0xFF53 || key == 0xFF98) changed = func_002D7468(self, 1);
        else unknown = 1;
    } else {
        if (key == 0xFF52 || key == 0xFF97) changed = func_002D7528(self, 1);
        else if (key == 0xFF54 || key == 0xFF99) changed = func_002D7468(self, 1);
        else unknown = 1;
    }
    if (func_00265D00(self)) {
        if (changed) func_002D6D18(self, arg1);
        else if (!unknown) {

    s32 newVal;
    s32 oldVal;
    MethodHandle h;
    s32 ret[4];
    Str s;
    s32 *pv;
    pv = ret;
    {
        Str *ps = &s;
        const char *src = D_0069CCC8;
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
    if (h.p != 0) {
        func_0030BB18(pv);
        {
            Value args[2];
            s32 tmp[4];
            s32 v1;
            s32 *p0;
            Value *dst;

            p0 = tmp;
            dst = args;
            v1 = arg1;
            func_00309348(p0, &v1);
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

            dst = &args[1];
            func_002FE278(p0, self->bc);
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
            func_002FC870(p0, 2);

            vcall20((VObj *)h.p, pv, 2, args);
            DESTROY_ARGS();
            func_00309378(pv, 2);
        }
    }

        }
    }
    if (changed) return 2;
    return mWidget__onKeyPress(self, arg1, event);
}
