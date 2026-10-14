#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 hModule__getName();                                /* extern */
M2C_UNK func_00485F48(s32, void *);                 /* extern */
M2C_UNK func_005A5A30(void *, M2C_UNK, M2C_UNK, s32, s32); /* extern */

extern char D_00698450[];
void func_00229EE8(s32 arg0, s32 arg1) {
    struct StackFrame_00229EE8 { s8 pad0[0x80]; } sp_;
    func_005A5A30(((s8 *)&sp_), 0x80, (s32)D_00698450, hModule__getName(), arg1);
    func_00485F48(arg0 + 0xB0, ((s8 *)&sp_));
}
