/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00576788(s32);                         /* extern */
M2C_UNK func_005767C0(s32);                         /* extern */
M2C_UNK func_005768D8(s32);                         /* extern */

void func_004AE068(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x3048;
    func_00576788(temp_s1);
    M2C_FIELD(arg0, s32 *, 0x3078) = (s32) (M2C_FIELD(arg0, s32 *, 0x3078) - 1);
    func_005768D8(temp_s1);
    func_005767C0(temp_s1);
}
