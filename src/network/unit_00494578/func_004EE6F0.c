#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004EE578(void *, s32, s32, s32);       /* extern */

void func_004EE6F0(void *arg0, s32 arg1) {
    func_004EE578(arg0, M2C_FIELD(arg0, s32 *, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x44) + (arg1 * 0x70) + 0x60);
}
