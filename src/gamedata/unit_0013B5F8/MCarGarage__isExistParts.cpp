/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef long long s64;

struct RefCounter;
struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};
struct VObj {
    char pad0[4];
    VEntry *vtbl;
};
struct Arg3 {
    VObj *a;
    VObj *b;
};
struct Local {
    char pad0[0x18];
};
extern "C" void func_0013BD68(void *, int) throw();
extern "C" void func_0013BDC0(void *, s32) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" s64 func_0044A048(void *o, s64 key, s32 arg2);

static inline s32 vcall_58(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void MCarGarage__isExistParts(s32 *arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    if (arg2 >= 2) {
        s32 s0;
        func_0013BDC0(buf0, arg1);
        s0 = vcall_58(arg3->a);
        s32 r2 = vcall_58(arg3->b);
        s32 res = ~func_0044A048((char *)buf0[0] + 0x18, s0, r2) != 0;
        s32 *p = buf1;
        func_002FE278(p, res);
        if (arg0 != p) {
            s32 v = *p;
            if (v != 0) {
                func_003285A8((RefCounter *)v);
            }
            s32 old = *arg0;
            if (old != 0) {
                func_003285F8((RefCounter *)old);
            }
            *arg0 = v;
        }
        func_002FC870(p, 2);
        func_0013BD68(buf0, 2);
    }
}
