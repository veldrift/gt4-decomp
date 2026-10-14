/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

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
    char pad0[0xBC];
    s32 bc;
    char padC0[0x34];
    VObj *hF4;
};

struct Str1 {
    char pad[0xDC];
    char *p;
};

extern char D_0069CE18[];

extern "C" Str1 *func_002319C0(char *arg0);
extern "C" void func_0023DDF0(void *arg0, int arg1);
extern "C" void func_0023F8C8(s32 a0, const char *a1);
extern "C" void func_0023FB80(void *arg0);
extern "C" void func_002FC870(void *h, int flags);
extern "C" void func_002FE278(void *h, s32 v);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_0030BB18(void *h);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

extern "C" void func_002DAB50(Obj *self, char *arg1) {
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->hF4;
    if (*ph != 0) {
        Str1 *o = func_002319C0(arg1);
        if (o != 0) {
            s32 x[4];
            char **pp = &o->p;
            func_0023FB80(x);
            const char *str;
            s32 xv = x[0];
            s32 len = *(s32 *)(*pp - 0x10);
            if (len == 0) {
                str = D_0069CE18;
            } else {
                (*pp)[len] = 0;
                str = *pp;
            }
            func_0023F8C8(xv, str);
            func_0023DDF0(x, 2);
        }
        {
            s32 ret[4];
            func_0030BB18(ret);
            Value args[2];
            s32 tmp[4];
            s32 v1;
            s32 *p0;
            Value *dst;

            p0 = tmp;
            dst = args;
            v1 = (s32)arg1;
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

            vcall20(*ph, ret, 2, args);
            {
                Value *q = args + 2;
                while (args != q) {
                    --q;
                    func_00309378(q, 2);
                }
            }
            func_00309378(ret, 2);
        }
    }
}
