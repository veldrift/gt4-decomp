typedef int s32;
extern s32 D_0064A308;
extern s32 D_0064A338;
extern s32 D_0064A350;
extern "C" s32 func_0052F7B0(s32 *);
extern "C" s32 func_0050ABA8(void);
extern "C" s32 func_00506390(void);
extern "C" s32 func_0052FA88(void);
extern "C" s32 func_0050B658(void) {
    s32 local = 0;
    func_0052F7B0(&local);
    s32 st = D_0064A308;
    if (st != 1) return -15;
    s32 r = func_0050ABA8();
    if (r != 0) return r;
    if (D_0064A350 == st) func_00506390();
    s32 v = func_0052FA88();
    if (v != 0) {
        D_0064A338 = v;
        return -10;
    }
    return v;
}
