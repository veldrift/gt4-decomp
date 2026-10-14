typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F0E98(s32, s32);
extern "C" s32 func_001F0FC8(s32, s32);
extern "C" void func_00221AD0(void *, int);
extern "C" void func_00221B28(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MNetwork__initializeNetwork(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 bufx[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 res;
    s32 newVal;
    s32 oldVal;
    res = 0;
    if (arg2 == 1) {
        func_001DC650(buf0, arg1);
        s32 *p_s0 = buf2;
        s32 s1 = buf0[0];
        func_00221B28(p_s0, arg3);
        res = func_001F0E98(s1, *p_s0 + 0x10);
        func_00221AD0(p_s0, 2);
        func_001DC5F8(buf0, 2);
    } else if (arg2 >= 2) {
        func_002FC8C8(buf0, arg3);
        s32 *p_s0 = buf3;
        func_001DC650(p_s0, arg1);
        s32 s1 = *p_s0;
        res = func_001F0FC8(s1, func_002FE250(buf0[0]));
        func_001DC5F8(p_s0, 2);
        func_002FC870(buf0, 2);
    }
    func_002FE278(buf0, res);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf0, 2);
}
