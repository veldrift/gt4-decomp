typedef int s32;

struct RefCounter;

extern "C" void func_002F2A08(void *arg0, int arg1);
extern "C" void func_002F2A60(void *arg0, void *arg1);
extern "C" s32 func_002F3A88(s32 *arg0, s32 *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_002F2CB0(s32 *arg0, void *arg1, int arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p2;
    s32 v;
    s32 newVal;
    s32 oldVal;

    func_002F2A60(buf0, arg1);
    func_002F2A60(buf1, arg3);
    v = func_002F3A88(buf0, buf1);
    p2 = buf2;
    func_002FE278(p2, (void *)v);
    if (arg0 != p2) {
        newVal = *p2;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(p2, 2);
    func_002F2A08(buf1, 2);
    func_002F2A08(buf0, 2);
}
