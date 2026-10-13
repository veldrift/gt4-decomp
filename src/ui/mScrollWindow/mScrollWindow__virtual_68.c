#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_002D1FF8();                    /* extern */

void mScrollWindow__virtual_68(void *arg0, s32 arg1) {
    func_002D1FF8(arg0 + 0xC4);
    func_002D1FF8(arg0 + 0xFC, arg1);
    M2C_FIELD(arg0, s32 *, 0xC0) = 0;
    M2C_FIELD(arg0, s32 *, 0xBC) = 0;
}
