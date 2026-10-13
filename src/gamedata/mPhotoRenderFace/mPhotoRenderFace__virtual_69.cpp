#include "types.h"

extern "C" void *func_00197798(void *);
extern "C" void func_0019AC98(void *, s32, void *, s32, s32);
extern "C" void mColorChipFace__virtual_69(void *, s32, s32);

extern "C" void mPhotoRenderFace__virtual_69(void *arg0, void *arg1, s32 arg2) {
    mColorChipFace__virtual_69(arg0, (s32)arg1, 0);

    if (arg2 == 0) {
        return;
    }

    s32 value = *(s32 *)((u8 *)arg1 + 0x10);
    void *object = func_00197798(arg1);
    if (object != 0 && *(s32 *)((u8 *)object + 0x1E634) != 0) {
        return;
    }

    s32 current = *(s32 *)((u8 *)arg0 + 0xB8);
    s32 other = *(s32 *)((u8 *)arg0 + 0xB4);
    *(s32 *)((u8 *)arg0 + 0xB8) = 0;
    if (current != 0) {
        func_0019AC98(arg0, value, arg1, current, other);
    }
}
