typedef int s32;

struct Obj {
    char pad0[0xA4];
    s32 z;
    s32 h;
    s32 h2;
};

extern "C" void mTextFace__virtual_68(void);
extern "C" void func_00291018(void *arg0, s32 *arg1);
extern "C" void func_00291048(void *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void mFlashFace__virtual_68(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 zero2;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    mTextFace__virtual_68();
    self->z = 0;
    zero = 0;
    func_00291018(buf, &zero);
    dst = &self->h;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_00291048(buf, 2);
    zero2 = 0;
    func_00291018(buf, &zero2);
    dst = &self->h2;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_00291048(buf, 2);
}
