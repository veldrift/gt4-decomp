typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00151888(void *);
extern "C" void func_002F7BC0(void *, void *);
extern "C" f32 func_002F9158(s32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_00151830(void *, s32);

extern "C" void MCarModel__set_ty(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    f32 t1;
    if (arg2 > 0) {
        func_00151888(buf0);
        p_s0 = buf1;
        func_002F7BC0(p_s0, arg3);
        v_s1 = buf0[0];
        t1 = func_002F9158(*p_s0);
        *(f32 *)((char *)v_s1 + 0x18) = t1;
        func_002F7B68(p_s0, 0x2);
        func_00151830(buf0, 0x2);
    }
}
