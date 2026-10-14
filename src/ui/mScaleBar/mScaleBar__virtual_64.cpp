typedef int s32;

struct RefCounter;

struct Obj {
    char pad0[0xF8];
    s32 h;
    s32 h2;
};

extern "C" void IfWidget__structor_0(Obj *arg0, void *arg1);
extern "C" void func_002F9B08(void *arg0, s32 *arg1);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void mScaleBar__virtual_64(Obj *self, void *arg1) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    IfWidget__structor_0(self, arg1);
    zero = 0;
    func_002F9B08(buf, &zero);
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
    func_002F9B38(buf, 2);
    zero2 = 0;
    func_002F9B08(buf, &zero2);
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
    func_002F9B38(buf, 2);
}
