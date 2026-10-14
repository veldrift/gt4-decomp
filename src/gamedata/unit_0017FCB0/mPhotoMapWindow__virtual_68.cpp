typedef int s32;

struct Obj {
    char pad0[0xC0];
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    char pad1[8];
    s32 f0D8;
    s32 f0DC;
    s32 f0E0;
    s32 h;
};

extern "C" void mTextFace__virtual_68(Obj *self);
extern "C" void func_002F9B08(void *arg0, s32 *arg1);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void mPhotoMapWindow__virtual_68(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    mTextFace__virtual_68(self);
    self->f00 = 0;
    self->f04 = 0;
    self->f08 = 0;
    self->f0C = 0;
    self->f0D8 = 0;
    self->f0DC = 0;
    self->f0E0 = 0;
    zero = 0;
    func_002F9B08(buf, &zero);
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
    func_002F9B38(buf, 2);
}
