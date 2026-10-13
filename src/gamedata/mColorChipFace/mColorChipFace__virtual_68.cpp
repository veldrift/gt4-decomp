typedef int s32;
struct RefCounter;
struct Owner { char pad0[0xA8]; s32 *slots[2]; };
extern "C" void mTextFace__virtual_68(Owner *self);
extern "C" void func_002106E0(void *, s32 *);
extern "C" void func_00210710(void *, s32);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);
extern "C" void mColorChipFace__virtual_68(Owner *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    s32 count;
    mTextFace__virtual_68(self);
    dst = (s32 *)&self->slots[0];
    count = 1;
    do {
        zero = 0;
        func_002106E0(buf, &zero);
        if (dst != buf) {
            newVal = buf[0];
            if (newVal != 0) func_003285A8((RefCounter *)newVal);
            oldVal = *dst;
            if (oldVal != 0) func_003285F8((RefCounter *)oldVal);
            *dst = newVal;
        }
        func_00210710(buf, 2);
        dst += 1;
        count -= 1;
    } while (count >= 0);
}
