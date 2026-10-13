typedef int s32;
typedef short s16;

struct RefCounter;

extern "C" void func_001A0B50(void *arg0, void *arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 *func_002EFCE0(void *h, s32 arg);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_001A0AF8(void *arg0, s32 arg1);

extern "C" void func_001A26D0(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *s5;
    s32 *p_s4;
    s32 *p_s2;
    s32 *s1;
    s32 newVal;
    s32 oldVal;

    func_001A0B50(buf0, arg1);
    p_s4 = buf1;
    s5 = (char *)buf0[0] + 0x10;
    func_002EFC48(p_s4, 2);
    s1 = func_002EFCE0(p_s4, 0);
    p_s2 = buf2;
    func_002FE278(p_s2, (void *)(s32)*(s16 *)(s5 + 0x38));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = func_002EFCE0(p_s4, 1);
    func_002FE278(p_s2, (void *)(s32)*(s16 *)(s5 + 0x3A));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    if (arg0 != p_s4) {
        newVal = p_s4[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002ED5C0(p_s4, 2);
    func_001A0AF8(buf0, 2);
}
