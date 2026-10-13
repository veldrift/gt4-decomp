#include "types.h"

extern "C" void mTextFace__virtual_68(void *);
extern "C" void func_001C95B0(void *, s32);
extern "C" s32 func_00197788(s32);
extern "C" s32 func_00197798(s32);
extern "C" void func_00335580(s32);

struct PhotoRenderFace_0019B668 {
    u8 pad0[0xA0];
    void *handle;
};

extern "C" void mPhotoRenderFace__virtual_68(PhotoRenderFace_0019B668 *self, s32 arg1) {
    void *owner = self;
    mTextFace__virtual_68(owner);
    void **handle_slot = (void **)((u8 *)owner + 0xA0);
    if (*handle_slot != 0) {
        func_001C95B0(*handle_slot, 3);
    }
    *handle_slot = 0;
    s32 first = func_00197788(arg1);
    if (first != 0 && func_00197798(arg1) != 0) {
        func_00335580(first);
    }
}
