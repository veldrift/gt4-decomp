typedef int s32;

struct RefCounter;

struct Struct_0013A548 {
    char pad0[0xCC];
    s32 unkCC;
    char pad1[0x2A4 - 0xD0];
    s32 unk2A4;
    s32 unk2A8;
};

extern "C" void func_002638D0(Struct_0013A548 *self);
extern "C" void func_0013BD38(void *arg0, s32 *arg1);
extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_00151800(void *arg0, s32 *arg1);
extern "C" void func_00151830(void *arg0, int arg1);
extern "C" void func_002106E0(void *arg0, s32 *arg1);
extern "C" void func_00210710(void *arg0, int arg1);
extern "C" void func_0013A548(Struct_0013A548 *arg0);
extern "C" void func_0013A650(Struct_0013A548 *arg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_0013AEE0(Struct_0013A548 *self) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 zero3;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_002638D0(self);
    zero = 0;
    func_0013BD38(buf, &zero);
    dst = &self->unk2A8;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_0013BD68(buf, 2);
    zero2 = 0;
    func_00151800(buf, &zero2);
    dst = &self->unk2A4;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_00151830(buf, 2);
    zero3 = 0;
    func_002106E0(buf, &zero3);
    dst = &self->unkCC;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_00210710(buf, 2);
    func_0013A548(self);
    func_0013A650(self);
}
