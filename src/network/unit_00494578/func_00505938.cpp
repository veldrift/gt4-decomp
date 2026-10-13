typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef signed char s8;

struct Rec505938 {
    char pad0[0x12];
    s16 h12;
    s16 h14;
    s16 h16;
    s16 h18;
    s32 w1C;
};

extern s16 D_0064A164;
extern s32 D_0064A150;
extern char D_006C12A8[];

extern "C" void func_00504B08(s32 a);
extern "C" s32 func_0052EAF8(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern "C" void func_0057D9C0(const char *fmt, ...);

extern "C" s32 func_00505938(struct Rec505938 *arg0) {
    s32 r;
    s32 c;

    r = -0xC;
    if (arg0->h16 < 0)
        return r;
    if (arg0->h12 < 0)
        return r;
    if (arg0->h18 < 0)
        return r;
    if (arg0->h14 < 0)
        return r;
    if ((u32)arg0->w1C >= 4)
        arg0->w1C = 0;
    r = -0xC;
    if (D_0064A164 != 1)
        return r;
    func_00504B08((s32)arg0);
    c = func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 0, 0x20, (s32)arg0);
    if (c == 0)
        return c;
    func_0057D9C0(D_006C12A8, c);
    return -5;
}
