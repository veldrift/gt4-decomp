#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0069A5B8[];
extern char mStorageMC__vtable[];
s32 mStorage__structor_0(s32);
void func_00240398(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void mStorageMC__structor_0(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x14, 4, D_0069A5B8);
    mStorage__structor_0(temp_v0);
    *(s32 *)(temp_v0 + 4) = (s32)mStorageMC__vtable;
    sp[0] = temp_v0;
    func_00240398(arg0, sp);
}
