/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" s32 func_001F69A0(s32, s32, s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct Tmp {
 s32 v[4];
 Tmp(void *x) { func_002FC8C8(this,x); }
 s32 get() const { return v[0]; }
 ~Tmp() { func_002FC870(this,2); }
};
extern "C" void MNetwork__getAvailableGameIdLAN(s32 *arg0, s32 arg1, s32 arg2, char *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s6;
    s32 *p_s5;
    s32 *p_s1;
    s32 s3;
    s32 s4;
    s32 s7;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 2) {
        s7 = 0;
        func_001DC650(buf0, arg1);
        p_s6 = buf1;
        func_002FC8C8(p_s6, arg3);
        p_s5 = buf2;
        func_002FC8C8(p_s5, arg3 + 4);
        s4 = func_002FE250(*p_s6);
        s3 = func_002FE250(*p_s5);
        if (arg2 >= 3) {
            Tmp tmp(arg3 + 8);
            s7 = func_002FE250(tmp.get());
        }
        s32 buf3[4];
        p_s1 = buf3;
        func_002FE278(p_s1, func_001F69A0(buf0[0], s4, s3, s7));
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 2);
        func_002FC870(p_s5, 2);
        func_002FC870(p_s6, 2);
        func_001DC5F8(buf0, 2);
    }
}
