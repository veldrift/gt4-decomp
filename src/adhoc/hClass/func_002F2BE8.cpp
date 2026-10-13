typedef int s32;

struct RefCounter;

extern "C" void func_002F2A08(void *arg0, int arg1);
extern "C" void func_002F2A60(void *arg0, void *arg1);
extern "C" s32 func_002F3A70(s32 *arg0, s32 *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_002F2BE8(s32 *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    s32 r;

    func_002F2A60(buf0, arg1);
    func_002F2A60(buf1, (void *)arg3);
    r = func_002F3A70(buf0, buf1);
    p_s2 = buf2;
    func_002FE278(p_s2, (void *)r);
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(p_s2, 2);
    func_002F2A08(buf1, 2);
    func_002F2A08(buf0, 2);
}
