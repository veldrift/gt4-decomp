typedef int s32;
typedef long s64;
typedef unsigned char u8;

extern "C" s32 func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, s32 arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 func_00147D80(void *arg0);
extern "C" s64 func_00440AF0(void *arg0);
extern "C" s32 *HArray__operator_index(void *h, s32 arg);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void MCarGarage__getRacingModifyRange(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 *s1;
    u8 *s3;
    s64 s0;
    u8 s5 = 0;
    u8 s6 = 0;
    s32 newVal;
    s32 oldVal;

    func_0013BDC0(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_0013BD68(buf0, 2);
    func_002EFC48(buf0, 4);
    p_s2 = buf1;
    func_0013BDC0(p_s2, arg1);
    s0 = func_00440AF0((void *)func_00147D80((void *)p_s2[0]));
    func_0013BD68(p_s2, 2);
    if (s0 != -1) {
        s5 = s3[0x137];
        s6 = s3[0x138];
    }

    s1 = HArray__operator_index(buf0, 0);
    func_002FE278(p_s2, s3[0x5D] + s5);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = HArray__operator_index(buf0, 1);
    func_002FE278(p_s2, s3[0x5E] + s6);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = HArray__operator_index(buf0, 2);
    func_002FE278(p_s2, s3[0x60] + s5);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

    s1 = HArray__operator_index(buf0, 3);
    func_002FE278(p_s2, s3[0x61] + s6);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);

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
    func_002ED5C0(buf0, 2);
}
