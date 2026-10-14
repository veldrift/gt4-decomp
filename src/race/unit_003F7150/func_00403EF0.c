#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00385EC8(void *, s32);                 /* extern */
s32 *func_00385F80(void *);                         /* extern */
M2C_UNK func_00386148(M2C_UNK *, s32);              /* extern */
f32 *func_003863A8(M2C_UNK *);                      /* extern */
f32 *func_003863B8(M2C_UNK *);                      /* extern */
f32 *func_003863C8(M2C_UNK *);                      /* extern */

void func_00403EF0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    struct StackFrame_00403EF0 { s8 pad0[0x4]; s32 sp4; s8 pad1[0x8]; } sp_;

    func_00385EC8(((s8 *)&sp_), arg0);
    func_00386148(&sp_.sp4, arg0 + 0x40);
    *func_00385F80(((s8 *)&sp_)) = 0xB;
    *func_003863A8(&sp_.sp4) = fparg0;
    *func_003863B8(&sp_.sp4) = fparg1;
    *func_003863C8(&sp_.sp4) = fparg2;
}
