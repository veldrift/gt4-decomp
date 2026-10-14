typedef int s32;
struct Ops {
    char pad[0x70];
    s32 (*fn)(s32, s32, s32);
};
extern Ops *D_0064B4B4;
extern "C" s32 func_00535780(s32);
extern "C" s32 func_00536CF8(void);
extern "C" s32 func_00536D38(void);
extern "C" s32 func_00515BE8(s32 a0, s32 a1, s32 a2) {
    s32 r = func_00535780(func_00536CF8());
    if (r != 0) return r;
    s32 s0 = D_0064B4B4->fn(a0, a1, a2);
    s32 t = func_00535780(func_00536D38());
    r = (t == 0) ? s0 : t;
    return r;
}
