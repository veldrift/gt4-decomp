typedef int s32;
extern s32 D_0064A308;
extern "C" s32 func_0052F7B0(s32 *);
extern "C" s32 func_0050ABA8() throw();
extern "C" s32 func_0050B7A8(void) {
    s32 local = 0;
    func_0052F7B0(&local);
    if (D_0064A308 == 1) {
        return func_0050ABA8();
    }
    return -15;
}
