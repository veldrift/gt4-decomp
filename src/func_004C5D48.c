#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004C4070(s32, s32, M2C_UNK);           /* extern */
s32 func_004C5EC0(s32, s32, s32, void *, M2C_UNK);  /* extern */
M2C_UNK func_004C8B50();           /* extern */

s32 func_004C5D48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct StackFrame_004C5D48 { s32 sp0; s8 pad0[0xC]; } sp_;
    s32 temp_v0;

    sp_.sp0 = 0;
    temp_v0 = func_004C5EC0(arg0, arg1, arg2, ((s8 *)&sp_), 0);
    if (temp_v0 < 0) {
        func_004C8B50(arg0, sp_.sp0, 0x1C);
        return temp_v0;
    }
    func_004C4070(arg3, sp_.sp0, 0x1C);
    func_004C8B50(arg0, sp_.sp0);
    return 1;
}
