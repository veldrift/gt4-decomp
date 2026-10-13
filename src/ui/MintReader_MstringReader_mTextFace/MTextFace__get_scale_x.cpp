typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void * func_002F9360(void *, f32);
extern "C" void * func_002434C8(void *, void *);
extern "C" void func_00243470(void *, s32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct func_00244258_v_s0 {
    char pad0[0x2C];
    f32 unk2C;
    char pad1[4];
    f32 unk34;
};

extern "C" void func_00244258(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    s32 v_s0;
    char *s0;
    f32 t1;
    if (arg2 <= 0) {
        p_s1 = buf1;
        func_002434C8(p_s1, arg1);
        func_002F9360(buf0, *(f32 *)((char *)(*p_s1) + 0xCC));
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
        func_002F7B68(buf0, 0x2);
        func_00243470(p_s1, 0x2);
    } else {
        func_002434C8(buf0, arg1);
        v_s0 = buf0[0];
        s0 = (char *)v_s0 + 0xA0;
        t1 = vcall_60((char *)(*(s32 *)(char *)arg3));
        ((struct func_00244258_v_s0 *)s0)->unk2C = t1;
        ((struct func_00244258_v_s0 *)s0)->unk34 = t1;
        func_00243470(buf0, 0x2);
    }
}
