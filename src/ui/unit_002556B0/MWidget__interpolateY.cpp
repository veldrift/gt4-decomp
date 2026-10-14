typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

static inline f32 vcall60(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" s32 func_0025C0A0(s32 arg0, f32 fparg0, f32 fparg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MWidget__interpolateY(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    f32 f20;
    f32 f13;
    if (arg2 >= 2) {
        func_00255110(buf0, arg1);
        v_s0 = buf0[0];
        f20 = vcall60(arg3[0]);
        f13 = vcall60(arg3[1]);
        t1 = func_0025C0A0(v_s0, f20, f13);
        p_s1 = buf1;
        func_002FE278(p_s1, (void *)(t1 != 0));
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 0x2);
        func_002550B8(buf0, 0x2);
    }
}
