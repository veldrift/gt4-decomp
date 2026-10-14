typedef int s32;
struct Obj { char pad0[8]; s32 unk8; s32 unkC; char pad10[0xC]; s32 unk1C; };
extern "C" s32 func_005216D8(Obj *, s32 *);
extern "C" s32 func_005220F8(void);
extern "C" s32 func_005221B0(s32, s32, s32);
extern "C" s32 func_00522C48(s32, s32, s32 *);
extern "C" s32 func_00521058(Obj *arg0, s32 arg1, s32 *arg2) {
    s32 sp0;
    s32 r;
    *arg2 = 0;
    if (func_005220F8() == 0) return 2;
    s32 a = arg0->unkC;
    if (a != 0 && a != 2) return 0xC355;
    if (arg0->unk1C == 0 && a == 0) {
        sp0 = 0;
        r = func_005216D8(arg0, &sp0);
        if (r != 0) return r;
        if (sp0 == 0) {
            *arg2 = 0;
            return r;
        }
        arg0->unk1C = 1;
    }
    r = func_00522C48(arg0->unk8, arg1, arg2);
    if (r != 0) return r;
    func_005221B0(*arg2, 0, 0x28);
    return 0;
}
