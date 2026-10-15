/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct RefCounter;

extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, s32 arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 *HArray__operator_index(void *h, s32 arg);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MCarGarage__getLSDRange(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    u8 *s3;
    s32 newVal;
    s32 oldVal;

    func_0013BDC0(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_0013BD68(buf0, 2);
    func_002EFC48(buf0, 0x12);
    {
    s32 *s1 = HArray__operator_index(buf0, 0);
    p_s2 = buf1;
    func_002FE278(p_s2, (void *)(s32)s3[0xf8]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 1);
    func_002FE278(p_s2, (void *)(s32)s3[0xf9]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 2);
    func_002FE278(p_s2, (void *)(s32)s3[0xfc]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 3);
    func_002FE278(p_s2, (void *)(s32)s3[0xfd]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 4);
    func_002FE278(p_s2, (void *)(s32)s3[0x100]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 5);
    func_002FE278(p_s2, (void *)(s32)s3[0x101]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 6);
    func_002FE278(p_s2, (void *)(s32)s3[0x104]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 7);
    func_002FE278(p_s2, (void *)(s32)s3[0x105]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 8);
    func_002FE278(p_s2, (void *)(s32)s3[0x108]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 9);
    func_002FE278(p_s2, (void *)(s32)s3[0x109]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 10);
    func_002FE278(p_s2, (void *)(s32)s3[0x10c]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 11);
    func_002FE278(p_s2, (void *)(s32)s3[0x10d]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 12);
    func_002FE278(p_s2, (void *)(s32)s3[0xfa]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 13);
    func_002FE278(p_s2, (void *)(s32)s3[0xfe]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 14);
    func_002FE278(p_s2, (void *)(s32)s3[0x102]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 15);
    func_002FE278(p_s2, (void *)(s32)s3[0x106]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 16);
    func_002FE278(p_s2, (void *)(s32)s3[0x10a]);
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
    }

    {
    s32 *s1 = HArray__operator_index(buf0, 17);
    func_002FE278(p_s2, (void *)(s32)s3[0x10e]);
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
    }

    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002ED5C0(buf0, 2);
}
