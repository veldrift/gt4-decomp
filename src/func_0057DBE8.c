#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_0057DA80(M2C_UNK *, void *, M2C_UNK);  /* extern */
M2C_UNK func_0057DAD8(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0057DBA0(M2C_UNK *);                   /* extern */
s32 func_0057DE48(M2C_UNK *, s32, s32);             /* extern */

s32 func_0057DBE8(s32 arg0, s32 arg1) {
    struct StackFrame_0057DBE8 { s8 pad0[0x40]; s32 sp40; s8 pad1[0xC]; } sp_;
    s32 temp_s1;

    func_0057DA80(&sp_.sp40, ((s8 *)&sp_), 0x40);
    temp_s1 = func_0057DE48(&sp_.sp40, arg0, arg1);
    func_0057DBA0(&sp_.sp40);
    func_0057DAD8(&sp_.sp40, 2);
    return temp_s1;
}
