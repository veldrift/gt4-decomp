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

extern "C" void func_0016D848(void *, void *);
extern "C" void func_0016D7F0(void *, s32);
extern "C" void func_00435710(s32);

extern "C" void func_0016E028(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 v_s0;
    func_0016D848(buf0, arg1);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    func_0016D7F0(buf0, 0x2);
    func_00435710(v_s0);
}
