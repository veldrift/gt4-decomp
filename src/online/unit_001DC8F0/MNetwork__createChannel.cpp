typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F2A98(s32, s32, s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" s32 func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" s32 func_00314920(s32);
extern "C" s32 func_00314AD8(s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MNetwork__createChannel(s32 *arg0, void *arg1, s32 arg2, char *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s5;
    s32 *p_s4;
    s32 *p_s2;
    s32 s0;
    s32 s1;
    s32 s6;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 2) {
        s6 = 0;
        func_001DC650(buf0, arg1);
        p_s5 = buf1;
        func_00312370(p_s5, arg3);
        p_s4 = buf2;
        func_002FC8C8(p_s4, arg3 + 4);
        if (arg2 >= 3) {
            p_s2 = buf3;
            func_00312370(p_s2, arg3 + 8);
            s6 = func_00314AD8(*p_s2);
            func_00312318(p_s2, 2);
        } else {
            p_s2 = buf3;
        }
        s1 = buf0[0];
        s0 = func_00314920(*p_s5);
        func_002FE278(p_s2, func_001F2A98(s1, s0, s6, func_002FE250(*p_s4)) != 0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s2, 2);
        func_002FC870(p_s4, 2);
        func_00312318(p_s5, 2);
        func_001DC5F8(buf0, 2);
    }
}
