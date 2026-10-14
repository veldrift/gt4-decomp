typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_00284B18(void *, s32);
extern "C" void func_00284B70(void *, void *);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_002F9360(void *, f32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct VEntry_1C8 { s16 delta; s16 index; f32 (*fn)(void *, s32); };
struct VObj_1C8 { char pad0[4]; VEntry_1C8 *vtbl; };
static inline f32 vcall_1c8(char *o, s32 a) {
    VEntry_1C8 *e = (VEntry_1C8 *)((char *)((VObj_1C8 *)o)->vtbl + 0x1C8);
    return e->fn(o + e->delta, a);
}

extern "C" void MColorFace__get_alpha(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 var_s0;
    s32 newVal;
    s32 oldVal;
    f32 fv;
    func_00284B70(buf0, arg1);
    var_s0 = -1;
    if (arg2 > 0) {
        p_s3 = buf1;
        func_002FC8C8(p_s3, arg3);
        var_s0 = func_002FE250(p_s3[0]);
        func_002FC870(p_s3, 0x2);
    } else {
        p_s3 = buf1;
    }
    fv = vcall_1c8((char *)buf0[0], var_s0);
    func_002F9360(p_s3, fv);
    if (arg0 != p_s3) {
        newVal = *p_s3;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002F7B68(p_s3, 0x2);
    func_00284B18(buf0, 0x2);
}
