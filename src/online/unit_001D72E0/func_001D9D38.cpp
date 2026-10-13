typedef int s32;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, void *); };
struct Obj { char pad0[0xFC]; VObj *handler; s32 f100; };

extern "C" void func_0030BB18(void *h);
extern "C" void func_00309378(void *h, int flags);
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

/* func_001D9D38: if the handler at self+0xFC is set, builds two Values (the first from arg1,
   the second from the s32 at self+0x100), builds a result slot, invokes the handler (vtable
   slot 0xA8), destroys the result and the argument list, and returns 1; returns 0 otherwise. */
extern "C" s32 func_001D9D38(Obj *self, Value *arg1) {
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->handler;
    if (*ph == 0) {
        return 0;
    }
    {
        Value args[2];
        s32 ret[4];
        Value *dst;

        dst = args;
        if (dst != arg1) {
            newVal = arg1->p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = dst->p;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            dst->p = newVal;
        }

        dst = &args[1];
        if (dst != (Value *)&self->f100) {
            newVal = ((Value *)&self->f100)->p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = dst->p;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            dst->p = newVal;
        }

        func_0030BB18(ret);
        vcall20(*ph, ret, 2, args);
        func_00309378(ret, 2);

        {
            Value *q = args + 2;
            while (args != q) {
                --q;
                func_00309378(q, 2);
            }
        }
    }
    return 1;
}
