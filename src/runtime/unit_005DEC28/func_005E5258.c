#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_005E5258(void *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    MColorReader__structor_0(sp, M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) + (arg2 * 0x10));
    func_0024DB78(sp, arg1);
    MColorReader__structor_1(sp, 2);
}
