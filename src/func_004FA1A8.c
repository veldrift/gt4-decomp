#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004F9F18(void *, s32);                     /* extern */

s32 func_004FA1A8(void *arg0, s32 arg1) {
    if ((arg1 < 0) || (arg1 >= M2C_FIELD(arg0, s32 *, 0x3F44))) {
        return 0;
    }
    return func_004F9F18(arg0, M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x3F48));
}
