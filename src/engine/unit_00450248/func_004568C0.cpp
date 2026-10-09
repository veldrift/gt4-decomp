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

extern s32 D_008465F0;
extern "C" void func_0049CE68(void);

extern "C" void func_004568C0(s32 *arg0) {
    func_0049CE68();
    D_008465F0 = (s32)arg0;
}
