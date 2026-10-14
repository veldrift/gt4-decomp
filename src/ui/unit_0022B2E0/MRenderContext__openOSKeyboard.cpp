typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObjF {
    char pad0[4];
    char *vtbl;
};

static inline f32 vcallf(VObjF *o) {
    VEntryF *e = (VEntryF *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" s32 func_00232120(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MRenderContext__openOSKeyboard(s32 *arg0, void *arg1, s32 arg2, VObjF **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    f32 f22;
    f32 f21;
    f32 f20;
    s32 *p_s1;
    s32 r;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 4) {
        func_0022AD20(buf0, arg1);
        v_s0 = buf0[0];
        f22 = vcallf(arg3[0]);
        f21 = vcallf(arg3[1]);
        f20 = vcallf(arg3[2]);
        r = func_00232120(v_s0, f22, f21, f20, vcallf(arg3[3]));
        p_s1 = buf1;
        func_002FE278(p_s1, (void *)(s32)(r != 0));
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
        func_0022ACC8(buf0, 0x2);
    }
}
