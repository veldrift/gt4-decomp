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

extern char D_0068ECC0[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void func_00137F40(s32);
extern "C" void func_00255088(void *, void *);

extern "C" void func_00138140(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    v_s0 = func_00326750(0x2bc, 0x4, &D_0068ECC0);
    func_00137F40(v_s0);
    buf0[0] = v_s0;
    func_00255088(arg0, buf0);
}
