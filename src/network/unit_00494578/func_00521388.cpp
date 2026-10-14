typedef int s32;
typedef unsigned int u32;
struct Obj { char pad0[8]; s32 unk8; s32 unkC; };
extern "C" s32 func_005220F8(void);
extern "C" s32 func_005221B0(s32, s32, s32);
extern "C" s32 func_00522F18(s32, s32 *, s32 *, void *, u32, s32 *);
extern "C" s32 func_00521388(Obj *arg0, s32 *a1, s32 *a2, void *buf, u32 size, s32 *recv) {
    if (recv == 0) return 2;
    *recv = 0;
    if (buf == 0) return 2;
    if (func_005220F8() == 0) return 2;
    if (arg0->unkC != 1) return 0xC355;
    s32 r = func_00522F18(arg0->unk8, a1, a2, buf, size, recv);
    if (r != 0) return r;
    func_005221B0(0, *recv, 0x1C);
    return 0;
}
