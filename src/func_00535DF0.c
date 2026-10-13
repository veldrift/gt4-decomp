#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_0064B4B0[];
s32 func_00535DF0(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0 != 0) {
            M2C_FIELD(*(void **)D_0064B4B0, M2C_UNK (**)(s32), 0x80)(arg0 + 0x10C);
            return 0;
        }
        /* Duplicate return node #0x1.0000000000000p+2 Try simplifying control flow for better match */
        return 0x17;
    }
    return 0x17;
}
