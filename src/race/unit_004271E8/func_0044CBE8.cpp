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

extern "C" void func_0044CC18(void *, void *, void *, s32);

extern "C" void func_0044CBE8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    buf0[0] = 0;
    buf0[1] = 0;
    func_0044CC18(arg0, buf0, arg1, 0x1);
}
