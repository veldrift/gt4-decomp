#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00546D38(void *);                      /* extern */
M2C_UNK func_00546E00(void *, s32, s32);            /* extern */
M2C_UNK func_00546F98(void *, s32, s32);            /* extern */

void func_00542E18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct StackFrame_00542E18 { s8 pad0[0x60]; } sp_;
    func_00546D38(((s8 *)&sp_));
    if ((arg0 != 0) && (arg1 != 0)) {
        func_00546E00(((s8 *)&sp_), arg0, arg1);
    }
    func_00546E00(((s8 *)&sp_), arg2, arg3);
    func_00546F98(((s8 *)&sp_), arg4, arg5);
}
