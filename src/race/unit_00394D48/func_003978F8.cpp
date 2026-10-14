typedef int s32;
extern "C" void *func_00397868(void *arg0, void *arg1);
extern "C" void func_004AE268(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern "C" s32 func_003978F8(void *arg0, s32 arg1, s32 arg2) {
    s32 buf[16];
    s32 out[5];
    s32 *o = out;
    void *p = func_00397868(arg0, buf);
    func_004AE268(o, p, arg1, arg2, 1);
    return out[4];
}
