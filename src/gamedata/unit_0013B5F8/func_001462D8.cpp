#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" M2C_UNK func_00146198(s32, s32, s32, s32);          /* extern */
extern "C" f32 func_00146600();                                /* extern */
extern "C" f32 func_00472A08(M2C_UNK, f32);                    /* extern */

extern char PDISTD__UNIT_MANAGER[];
extern "C" void func_001462D8(s32 arg0, s32 arg1, s32 arg2) {
    func_00146198((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)((s32) ((func_00472A08((M2C_UNK)((s32)PDISTD__UNIT_MANAGER), (f32)(func_00146600())) * 0x1.9000000000000p+6f) + 0x1.0000000000000p-1f)));
}
