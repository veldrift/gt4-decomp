#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00104E30(M2C_UNK);                     /* extern */
s32 func_00436740(s32);                             /* extern */
M2C_UNK func_005C1628(s32);                         /* extern */

extern char D_0068D2C0[];
extern char D_00622F4C[];
void func_001103E0(s32 arg0, s32 arg1) {
    if (func_00436740(*(s32 *)D_00622F4C + 0x38CB0) != 0) {
        func_00104E30((s32)D_0068D2C0);
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
