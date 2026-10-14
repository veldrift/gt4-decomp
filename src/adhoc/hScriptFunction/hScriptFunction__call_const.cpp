typedef int s32;

struct RefCounter;

extern "C" void func_00319268(void *arg0);
extern "C" void func_0030BB18(void *a0);
extern "C" s32 hThread__execCode(void *arg0, s32 arg1, void *arg2, void *arg3, s32 arg4, s32 arg5);
extern "C" void func_00318538(void *arg0, int arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hScriptFunction__call_const(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s5;
    s32 *p_s6;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;

    func_00319268(buf0);
    p_s6 = buf2;
    v_s0 = buf0[0];
    p_s5 = buf1;
    func_0030BB18(p_s6);
    hThread__execCode(p_s5, v_s0, (char *)arg0 + 0xC, p_s6, arg2, arg3);
    if (arg1 != p_s5) {
        newVal = *p_s5;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_00309378(p_s5, 2);
    func_00309378(p_s6, 2);
    func_00318538(buf0, 2);
}
