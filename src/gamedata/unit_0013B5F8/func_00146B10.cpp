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

extern "C" void func_0013BDC0(void *, void *);
extern "C" s32 func_001467A0(s32);
extern "C" void func_0013BD68(void *, s32);

extern "C" s32 func_00146B10(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 t1;
    s32 v_s1;
    s32 t2;
    func_0013BDC0(buf0, arg0);
    t1 = func_001467A0(buf0[0]);
    p_s0 = buf1;
    v_s1 = t1;
    func_0013BDC0(p_s0, arg1);
    t2 = func_001467A0(*p_s0);
    v_s1 = (v_s1 < t2);
    func_0013BD68(p_s0, 0x2);
    func_0013BD68(buf0, 0x2);
    return v_s1;
}
