typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hInt__virtual_35(void *arg0, s32 *arg1, void *arg2, void *arg3, void **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 flag = 0;

    if (*(s32 *)((char *)arg0 + 0x10) != 0) {
        flag = vcall_58((char *)*arg4) != 0;
    }
    func_002FE278(buf0, (void *)flag);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_002FC870(buf0, 0x2);
}
