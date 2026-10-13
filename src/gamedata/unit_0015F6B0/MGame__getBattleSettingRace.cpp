typedef int s32;

struct RefCounter;

extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" s32 func_00575DC8(s32 arg0);
extern "C" void func_00200140(void *arg0, void *arg1, void *arg2);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_001FFF30(void *arg0, int arg1);
extern "C" void func_0015F388(void *arg0, int arg1);

struct BS_dst {
    s32 u0;
    s32 u4;
    s32 u8;
    s32 uC;
    s32 u10;
    s32 u14;
};

struct BS_src {
    char pad0[0x10E4];
    s32 u10E4;
    char pad10E8[0x14];
    s32 u10FC;
    s32 u1100;
    s32 u1104;
    s32 u1108;
};

extern "C" void func_00161F28(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 v_s1;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    func_0015F3E0(buf0, arg1);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    v_s1 = func_00575DC8(0x18);
    p_s2 = buf1;
    BS_src *src = (BS_src *)(0x38cb0 + v_s0);
    BS_dst *d = (BS_dst *)v_s1;
    d->u0 = src->u10FC;
    d->u4 = src->u1104;
    d->u8 = src->u1108;
    d->uC = (src->u1100 != 0);
    d->u10 = *(s32 *)((char *)v_s0 + 0x3A090);
    d->u14 = src->u10E4;
    func_00200140(p_s2, d, (void *)1);
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_001FFF30(p_s2, 2);
    func_0015F388(buf0, 2);
}
