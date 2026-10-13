typedef int s32;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, s32 *); };
struct Obj { char pad0[0x1C]; s32 f1C; VObj *handler; s32 f24; };

extern "C" void func_0030BB18(void *a0);
extern "C" int func_0022AC98(void *a0, s32 *a1);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

static inline void vcall20(VObj *o, s32 *ret, s32 n, s32 *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

/* mScriptWatcher__virtual_49: if the handler at +0x20 is set, builds a 1-element
   argument list from +0x1C, invokes the handler (vtable slot 0xA8) into a result,
   destroys the result and the argument list, and bumps the counter at +0x24. */
extern "C" void func_002CEB78(Obj *self) {
    s32 args[4];
    s32 tmp[4];
    s32 v1;
    s32 *p0;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->handler;
    if (*ph != 0) {
        func_0030BB18(args);
        {
            p0 = tmp;
            dst = args;
            v1 = self->f1C;
            func_0022AC98(p0, &v1);
            if (dst != p0) {
                newVal = *p0;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *dst;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *dst = newVal;
            }
            func_0022ACC8(p0, 2);
            func_0030BB18(p0);
            vcall20(*ph, p0, 1, args);
            self->f24 = self->f24 + 1;
            func_00309378(p0, 2);
        }
        {
            s32 *q = args + 1;
            while (args != q) {
                --q;
                func_00309378(q, 2);
            }
        }
    }
}
