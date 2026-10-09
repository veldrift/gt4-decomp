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

extern "C" void func_004AE440(void *, void *, s32, void *, void *);

extern "C" void * func_004AE370(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    buf0[0] = 0;
    buf0[1] = 0;
    buf0[2] = 0;
    buf0[3] = 0;
    func_004AE440(arg0, arg1, arg2, buf0, arg3);
    return arg0;
}
