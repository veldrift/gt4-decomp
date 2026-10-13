typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hFloat__virtual_35(void *arg0, s32 *arg1, void *arg2, void *arg3, void **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 flag = 0;
    s32 *dst = arg1;

    if (*(f32 *)((char *)arg0 + 0x10) != 0.0f) {
        if (vcall_60((char *)*arg4) != 0.0f) {
            flag = 1;
        }
    }
    func_002FE278(buf0, (void *)flag);
    if (dst != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_002FC870(buf0, 0x2);
}
