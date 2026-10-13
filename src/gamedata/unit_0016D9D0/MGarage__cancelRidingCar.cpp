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

extern "C" s32 func_0016D848(void *arg0, void *arg1);
extern "C" void func_0016D7F0(void *arg0, s32 arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" s32 func_00147D80(s32 arg0);
extern "C" void func_00435418(void *o, s32 a, s32 b);
extern "C" void func_0013BD68(void *arg0, s32 arg1);

extern "C" void func_0016E2A0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    char *s2;
    s32 v_s0;

    func_0016D848(buf0, arg1);
    s2 = *(char **)((char *)buf0[0] + 0x10);
    func_0016D7F0(buf0, 2);
    if (arg2 >= 0x2) {
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_0013BDC0(buf0, (char *)arg3 + 4);
        func_00435418(s2, v_s0, func_00147D80(buf0[0]));
        func_0013BD68(buf0, 0x2);
    }
}
