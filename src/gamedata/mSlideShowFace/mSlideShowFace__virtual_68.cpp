#include "types.h"
#include "m2c_macros.h"
extern "C" void mTextFace__virtual_68(void);
extern "C" void mUpdateContext__Sync(s32);
extern "C" void func_00578908(s32);
extern "C" void func_00578AF0(s32);
extern "C" void free(s32);
extern "C" void mSlideShowFace__virtual_68(void *self) {
    mTextFace__virtual_68();
    M2C_FIELD(self, s32 *, 0xA4) = 1;
    mUpdateContext__Sync(1);
    func_00578908(M2C_FIELD(self, s32 *, 0xA0));
    func_00578AF0(M2C_FIELD(self, s32 *, 0xA0));
    M2C_FIELD(self, s32 *, 0xA0) = 0;
    free(M2C_FIELD(self, s32 *, 0xB8));
    s32 *p = (s32 *)((char *)self + 0xB0);
    s32 count = 1;
    do {
        free(*p);
        p++;
        count--;
    } while (count >= 0);
}
