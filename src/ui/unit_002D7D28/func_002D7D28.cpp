typedef int s32;
typedef short s16;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { s16 delta; s16 index; void (*fn)(void *, s32 *, s32, void *); };
struct VEntryB { s16 delta; s16 index; s32 (*fn)(void *); };

extern "C" void func_0030BB18(void *h);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, s32 flags);
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

static inline s32 vcall58(char *o) {
    VEntryB *e = (VEntryB *)(((VObj *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

/* func_002D7D28: builds two Values from arg1 and arg2, a result slot, calls the
   object at *arg0 (vtable slot 0xA8), tests the returned object's slot 0x58 and
   returns its value, releasing the result and the argument list. */
extern "C" s32 func_002D7D28(VObj **arg0, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;
    s32 r;
    s32 ret[4];

    func_0030BB18(ret);
    {
        Value args[2];
        s32 tmp[4];
        s32 v1;
        s32 v2;
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
        v2 = arg2;
        func_00309348(p0, &v2);
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

        vcall20(*arg0, ret, 2, args);
        r = vcall58((char *)ret[0]);
        {
            Value *q = args + 2;
            while (args != q) {
                --q;
                func_00309378(q, 2);
            }
        }
        func_00309378(ret, 2);
    }
    return r;
}
