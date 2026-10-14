/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
struct RefCounter;
extern "C" void func_0015F388(void *, int) throw();
extern "C" void *func_0015F3E0(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0043AF68(s32);

static inline s32 ge(s32 a, s32 b) { return a >= b; }

extern "C" void MGame__isEnoughMoney(s32 *arg0, void *arg1, int arg2, Obj **arg3) {
    s32 buf0[4];
    s32 newVal, oldVal;
    if (arg2 > 0) {
        func_0015F3E0(buf0, arg1);
        s64 s0 = func_0043AF68(*(s32 *)(buf0[0] + 0x10) + 0x348);
        func_0015F388(buf0, 2);
        Obj *o = *arg3;
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        s32 v = e->fn((char *)o + e->delta);
        func_002FE278(buf0, s0 >= (s64)v);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0)
                func_003285A8(newVal);
            oldVal = *arg0;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
    }
}
