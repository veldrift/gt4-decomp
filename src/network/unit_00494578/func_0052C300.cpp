typedef int s32;
typedef unsigned int u32;
extern "C" s32 func_0052CC10(s32, s32 *);
extern "C" s32 func_0052CC90(s32, s32 *, s32);
extern "C" void func_0052CCD0(s32 *, s32, void *);
extern "C" s32 func_0052C300(s32 arg0, s32 arg1, s32 *arg2) {
    s32 sp0 = 0;
    if (arg2 == 0) return 0xD2F3;
    func_0052CCD0(arg2, arg1, &sp0);
    if (sp0 == 0) {
        s32 t = *arg2;
        if (t == 0xD) {
            *arg2 = 4;
            return func_0052CC90(arg0, arg2, arg1);
        }
        if ((u32)(t - 5) < 2) return func_0052CC90(arg0, arg2, arg1);
        *arg2 = 2;
        return func_0052CC10(arg0, arg2);
    }
    return func_0052CC90(arg0, arg2, arg1);
}
