typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Obj;

extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" char *func_00314AD8(Obj *arg0);
extern "C" void func_0042FCE0(s32 arg0, s32 arg1);
extern "C" void func_00312318(void *arg0, s32 arg1);
extern "C" void func_0015F388(void *arg0, s32 arg1);

extern "C" void func_00163680(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_0015F3E0(buf0, arg1);
        p_s1 = buf1;
        func_00312370(p_s1, arg3);
        v_s0 = *(s32 *)((char *)buf0[0] + 0x10) + 0x3A368;
        func_0042FCE0(v_s0, (s32)func_00314AD8((Obj *)*p_s1));
        func_00312318(p_s1, 0x2);
        func_0015F388(buf0, 0x2);
    }
}
