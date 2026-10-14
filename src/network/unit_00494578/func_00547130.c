#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_005471C0(void *);                      /* extern */
M2C_UNK func_00547200(void *, s32, s32);            /* extern */
M2C_UNK func_00547360(s32, void *);                 /* extern */

void func_00547130(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct StackFrame_00547130 { s8 pad0[0x60]; } sp_;
    func_005471C0(((s8 *)&sp_));
    if (arg0 != 0) {
        if (arg1 != 0) {
            func_00547200(((s8 *)&sp_), arg0, arg1);
        }
    }
    func_00547200(((s8 *)&sp_), arg2, arg3);
    func_00547360(arg4, ((s8 *)&sp_));
}
