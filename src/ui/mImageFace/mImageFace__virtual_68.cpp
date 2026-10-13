typedef int s32;

struct RefCounter;

struct Obj {
    char pad0[0xBC];
    s32 unkBC;
    s32 h;
    s32 h2;
};

extern "C" void func_002638D0(Obj *self);
extern "C" void func_002106E0(void *arg0, s32 *arg1);
extern "C" void func_00210710(void *arg0, int arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_002A2530(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_002638D0(self);
    self->unkBC = 0;
    zero = 0;
    func_002106E0(buf, &zero);
    dst = &self->h;
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
    zero2 = 0;
    func_002106E0(buf, &zero2);
    dst = &self->h2;
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
}
