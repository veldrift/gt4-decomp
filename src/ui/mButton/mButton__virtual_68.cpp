typedef int s32;

extern "C" void func_002F9B08(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mTextFace__virtual_68(s32 *, s32);

extern "C" void mButton__virtual_68(s32 *arg0, s32 arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    p_s1 = (s32 *)((char *)arg0 + 0xB0);
    buf1[0] = 0;
    func_002F9B08(buf0, buf1);
    if ((char *)p_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *p_s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *p_s1 = newVal;
    }
    func_002F9B38(buf0, 2);
    mTextFace__virtual_68(arg0, arg1);
}
