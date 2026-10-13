typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct Obj;

struct Sub {
    char pad[4];
    u8 unk4;
    s8 unk5;
};

extern "C" s32 func_0035C7C8(Obj *arg0);
extern "C" s32 func_0035C9B0(s32 arg0);

extern "C" void func_0035CDE0(Obj *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = 0.5f;
    *arg2 = 0.5f;
    if (func_0035C7C8(arg0) != 0) {
        Sub *s = (Sub *)((char *)arg0 + 0x788);
        *arg1 -= (f32)s->unk5 / 60.0f;
        *arg2 += (f32)func_0035C9B0(s->unk4) / 24.0f;
    }
}
