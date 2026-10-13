typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern s32 D_006193D8;
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void func_0026DB68(s32 *arg0, s32 arg1, char **arg2) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 t1;
    if (arg1 == 0) {
        func_002FE278(buf0, D_006193D8);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 0x2);
    } else {
        if (arg1 == 1) {
            t1 = vcall_58(*arg2);
            D_006193D8 = t1;
        }
    }
}
