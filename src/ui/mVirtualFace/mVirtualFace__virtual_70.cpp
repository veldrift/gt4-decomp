typedef int s32;
typedef short s16;

struct VObj { char pad0[4]; char *vtbl; };
struct Obj { char pad0[0xA0]; VObj *handler; };
struct VEntryA8 { s16 delta; s16 index; void (*fn)(void *, s32 *, s32, void *); };
struct VEntry2E8 { s16 delta; s16 index; void (*fn)(void *, s32); };

extern "C" void mWidget__virtual_70(void *a0, s32 a1, s32 a2);
extern "C" void func_0030BB18(void *h);
extern "C" void func_0022AC98(void *h, s32 *val);
extern "C" void func_0022ACC8(void *h, s32 flags);
extern "C" void func_00255088(void *h, s32 *val);
extern "C" void func_002550B8(void *h, s32 flags);
extern "C" void func_002556B0(void *h);
extern "C" void func_00309378(void *h, s32 flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

static inline void vcall_A8(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryA8 *e = (VEntryA8 *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

/* mVirtualFace__virtual_70: calls mWidget__virtual_70, then if the handler at self+0xA0 and arg2
   are set, builds two Values (arg1 and self), invokes the handler (vtable slot 0xA8), calls
   slot 0x2E8 on the returned object with arg1, and releases the temporaries. */
extern "C" void mVirtualFace__virtual_70(void *arg0, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;
    Obj *self = (Obj *)arg0;
    VObj **ph = &self->handler;

    mWidget__virtual_70(arg0, arg1, 0);
    if (*ph != 0 && arg2 != 0) {
        Value args[2];
        s32 tmp[4];
        s32 v1;
        s32 v2;
        s32 *p0;
        Value *dst;

        p0 = tmp;
        dst = args;
        v1 = arg1;
        func_0022AC98(p0, &v1);
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
        func_0022ACC8(p0, 2);

        dst = &args[1];
        v2 = (s32)arg0;
        func_00255088(p0, &v2);
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
        func_002550B8(p0, 2);
        func_002556B0(p0);

        vcall_A8(*ph, p0, 2, args);
        {
            VObj *r = (VObj *)p0[0];
            if (r != 0) {
                VEntry2E8 *e = (VEntry2E8 *)(r->vtbl + 0x2E8);
                e->fn((char *)r + e->delta, arg1);
            }
        }
        func_002550B8(p0, 2);
        {
            Value *q = args + 2;
            while (args != q) {
                --q;
                func_00309378(q, 2);
            }
        }
    }
}
