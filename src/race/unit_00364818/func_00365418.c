#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00343490(void *);                      /* extern */
M2C_UNK func_00361908(s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, void *); /* extern */

extern char D_006203C8[];
void func_00365418(void *arg0) {
    struct StackFrame_00365418 { s8 pad0[0x20]; } sp_;
    s32 temp_a0;

    if (M2C_FIELD(arg0, u8 *, 4) == 0) {
        func_00343490(((s8 *)&sp_));
        temp_a0 = M2C_FIELD(arg0, s32 *, 0);
        func_00361908(temp_a0 + 0x600, temp_a0, 0, 0, (s32)D_006203C8, ((s8 *)&sp_));
    }
}
