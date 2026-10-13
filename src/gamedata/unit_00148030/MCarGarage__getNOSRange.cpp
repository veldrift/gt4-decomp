typedef int s32;
typedef unsigned char u8;

extern "C" void func_0013BDC0(void *, void *);
extern "C" void func_0013BD68(void *, s32);
extern "C" void func_002EFC48(void *, s32);
extern "C" s32 *HArray__operator_index(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MCarGarage__getNOSRange(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 *s1;
    u8 *s3;
    s32 newVal;
    s32 oldVal;

    func_0013BDC0(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_0013BD68(buf0, 2);
    func_002EFC48(buf0, 3);

    s1 = HArray__operator_index(buf0, 0);
    p_s2 = buf1;
    func_002FE278(p_s2, s3[0x13F]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8(oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = HArray__operator_index(buf0, 1);
    func_002FE278(p_s2, s3[0x140]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8(oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = HArray__operator_index(buf0, 2);
    func_002FE278(p_s2, s3[0x141]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8(oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *arg0;
        if (oldVal != 0) func_003285F8(oldVal);
        *arg0 = newVal;
    }
    func_002ED5C0(buf0, 2);
}
