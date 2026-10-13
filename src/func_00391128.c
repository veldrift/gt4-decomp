#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_003B15B8(void *);                      /* extern */

M2C_UNK func_00391128(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1670) != 0) {
        func_003B15B8(arg0 + 0x5E0);
        if (M2C_FIELD(arg0, s32 *, 0x1674) != 0) {
            func_003B15B8(arg0 + 0xE20);
        }
    }
}
