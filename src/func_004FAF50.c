/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004FAD48(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_004FAE60(s32);                         /* extern */

extern char D_004FAF30[];
void func_004FAF50(s32 arg0) {
    func_004FA0E0(arg0, 3);
    func_004FAD48(arg0, 3, 0x15F90, 0);
    func_005031B0();
    func_004FAE60(arg0);
    func_004FA0E0(arg0, 4);
    func_004FAD48(arg0, 4, 0x15F90, (s32)D_004FAF30);
    func_00503240();
}
