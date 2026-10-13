#include "types.h"
#include "m2c_macros.h"
#define NULL 0

extern "C" s32 func_0057F260(s32);                             /* extern */
extern "C" M2C_UNK func_005A6AB0(s32, s32, s32);               /* extern */

extern char D_006187A8[];
extern "C" void func_00127A90(M2C_UNK arg0, s32 arg1) {
    s32 temp_v0;

    if (*(s32 *)D_006187A8 != 0) {
        temp_v0 = func_0057F260(arg1);
        func_005A6AB0(*(s32 *)D_006187A8 + 0x3C8, arg1, (temp_v0 < 0x40) ? temp_v0 : 0x3F);
    }
}
