typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_00266200(s32 arg0, s32 arg1);
extern "C" void func_002550B8(void *arg0, s32 arg1);

extern "C" void func_00256F30(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    func_00255110(buf0, arg1);
    v_s1 = buf0[0];
    func_00266200(v_s1, vcall_58((char *)(*(s32 *)(char *)arg3)) != 0);
    func_002550B8(buf0, 0x2);
}
