typedef int s32;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, void *); };
struct Obj { char pad0[0xD4]; VObj *handler; s32 f_d8; };

extern "C" s32 func_00265D00(Obj *arg0);
extern "C" void func_0030BB18(void *h);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_002FE278(void *h, s32 val);
extern "C" void func_002FC870(void *h, int flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

static inline void vcall_8C30(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

/* func_002C8E30: if func_00265D00(self) is nonzero and the handler at self+0xD4 is set,
   builds two Values (the first from arg1, the second from the s32 at self+0xD8), invokes
   the handler (vtable slot 0xA8) with a result slot, then destroys the arguments and the
   result. Returns void. */
extern "C" void func_002C8E30(void *arg0, s32 arg1) {
    s32 newVal;
    s32 oldVal;
    s32 argv = arg1;
    Obj *self = (Obj *)arg0;
    if (func_00265D00(self) != 0) {
        VObj **ph = &self->handler;
        if (*ph != 0) {
            s32 ret[4];

            func_0030BB18(ret);
            {
                Value args[2];
                s32 tmp[4];
                s32 v1;
                s32 *p0;
                Value *dst;

                p0 = tmp;
                dst = args;
                v1 = argv;
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
                func_002FE278(p0, self->f_d8);
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

                vcall_8C30(*ph, ret, 2, args);
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
}
