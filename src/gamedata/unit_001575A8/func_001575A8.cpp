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

extern char D_0068FD70[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void func_00154CF8(s32);
extern "C" void func_00151800(void *, void *);

extern "C" void func_001575A8(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    v_s0 = func_00326750(0xa60, 0x4, &D_0068FD70);
    func_00154CF8(v_s0);
    buf0[0] = v_s0;
    func_00151800(arg0, buf0);
}
