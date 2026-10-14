/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_00287CE0(void *, void *) throw();
extern "C" void func_00287C88(void *, s32) throw();
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" s32 func_00288DB0(s32, s32);
extern "C" void func_00204558(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00203620(void *, s32);
extern "C" void MColorWindow__getColor(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 index;
    s32 newVal;
    s32 oldVal;
    func_00287CE0(buf0, arg1);
    index = -1;
    if (arg2 > 0) {
        p_s3 = buf1;
        func_002FC8C8(p_s3, arg3);
        index = func_002FE250(p_s3[0]);
        func_002FC870(p_s3, 2);
    } else {
        p_s3 = buf1;
    }
    func_00204558(p_s3, func_00288DB0(buf0[0], index));
    if (arg0 != p_s3) {
        newVal = *p_s3;
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *arg0;
        if (oldVal != 0) func_003285F8(oldVal);
        *arg0 = newVal;
    }
    func_00203620(p_s3, 2);
    func_00287C88(buf0, 2);
}
