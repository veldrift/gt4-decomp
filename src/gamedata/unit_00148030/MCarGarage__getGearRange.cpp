/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct RefCounter;

extern "C" void *func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_0013BD68(void *arg0, s32 arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 *HArray__operator_index(void *h, s32 arg);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);


struct VEntry { short delta, index; int (*fn)(void *); };
struct VObj { int pad; VEntry *vtbl; };
extern "C" void *func_00147D80(void *);
extern "C" void *func_00441248(void *);
extern "C" void func_004413C8(void *, void *);
extern "C" int func_00445780(void *);
extern "C" unsigned char func_0043EBB8(void *);
extern "C" unsigned short func_0043EBE0(void *);
extern "C" void func_003553A0(void *, int, short, short *, short *);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void MCarGarage__getGearRange(s32 *arg0, void *arg1, int arg2, VObj **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    short lo[16];
    short hi[16];
    char data[0x600];
    s32 *p_s2;
    u8 *s3;
    s32 newVal, oldVal;
    func_0013BDC0(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_0013BD68(buf0, 2);
    func_002EFC48(buf0, 23);
    {
    s32 *s1 = HArray__operator_index(buf0, 0);
    p_s2 = buf1;
    func_002FE278(p_s2, (void *)(s32)(*(unsigned short *)(s3+0x24)));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 1);
    func_002FE278(p_s2, (void *)(s32)(*(unsigned short *)(s3+0x26)));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 2);
    func_002FE278(p_s2, (void *)(s32)(s3[0x32]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 3);
    func_002FE278(p_s2, (void *)(s32)(s3[0x33]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    func_0013BDC0(p_s2, arg1);
    void *ctx = func_00147D80((void *)*p_s2);
    func_0013BD68(p_s2, 2);
    func_004413C8(func_00441248(ctx), data);
    int gear = func_00445780(func_00441248(ctx));
    if (s3[0x32] < s3[0x33]) {
        if (arg2 > 0) {
            VObj *o = arg3[0];
            VEntry *e = &o->vtbl[11];
            data[0x156] = e->fn((char *)o + e->delta);
        }
        int n = func_0043EBB8(ctx) * 10;
        short x = func_0043EBE0(ctx);
        func_003553A0(data, n, x, lo, hi);
    } else {
        func_005A48D8(lo, 0, 32);
        func_005A48D8(hi, 0, 32);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 4);
    func_002FE278(p_s2, (void *)(s32)(gear));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 5);
    func_002FE278(p_s2, (void *)(s32)(lo[gear]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 6);
    func_002FE278(p_s2, (void *)(s32)(hi[1]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 7);
    func_002FE278(p_s2, (void *)(s32)(lo[0]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 8);
    func_002FE278(p_s2, (void *)(s32)(hi[0]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 9);
    func_002FE278(p_s2, (void *)(s32)(lo[1]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 10);
    func_002FE278(p_s2, (void *)(s32)(hi[1]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 11);
    func_002FE278(p_s2, (void *)(s32)(lo[2]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 12);
    func_002FE278(p_s2, (void *)(s32)(hi[2]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 13);
    func_002FE278(p_s2, (void *)(s32)(lo[3]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 14);
    func_002FE278(p_s2, (void *)(s32)(hi[3]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 15);
    func_002FE278(p_s2, (void *)(s32)(lo[4]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 16);
    func_002FE278(p_s2, (void *)(s32)(hi[4]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 17);
    func_002FE278(p_s2, (void *)(s32)(lo[5]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 18);
    func_002FE278(p_s2, (void *)(s32)(hi[5]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 19);
    func_002FE278(p_s2, (void *)(s32)(lo[6]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 20);
    func_002FE278(p_s2, (void *)(s32)(hi[6]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 21);
    func_002FE278(p_s2, (void *)(s32)(lo[7]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
        *s1 = newVal;
    }
    func_002FC870(p_s2, 2);
    }
    {
    s32 *s1 = HArray__operator_index(buf0, 22);
    func_002FE278(p_s2, (void *)(s32)(hi[7]));
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) func_003285A8((RefCounter *)newVal);
        oldVal = *s1;
        if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
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
