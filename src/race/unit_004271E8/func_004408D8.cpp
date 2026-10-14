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

extern "C" void func_00440170(void *, s32);

struct func_004408D8_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004408D8_v_s0 {
    char pad0[0xF8];
    s64 unkF8;
    char pad100[0x67];
    s8 unk167;
};
struct func_004408D8_arg2 {
    char pad0[0x13F];
    u8 unk13F;
};

extern "C" void func_004408D8(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    v_s0 = (char *)arg0 + (((((((struct func_004408D8_arg0 *)arg0)->unk490 << 1) + ((struct func_004408D8_arg0 *)arg0)->unk490) << 4) - ((struct func_004408D8_arg0 *)arg0)->unk490) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_004408D8_v_s0 *)v_s0)->unkF8 = (s64)arg1;
    func_00440170(arg0, arg2);
    ((struct func_004408D8_v_s0 *)v_s0)->unk167 = (s8)*(u8 *)((char *)arg2 + 0x13f);
}
