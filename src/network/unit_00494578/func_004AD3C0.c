/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00574EE8(s32);                         /* extern */
void func_00576788(void *);                      /* extern */
M2C_UNK func_005767C0(void *);                      /* extern */
M2C_UNK func_0057CB00(s32, void *);                 /* extern */

void func_004AD3C0(s32 arg0, void *arg1) {
    void *temp_s2;

    temp_s2 = arg0 + 0x10;
    func_00576788(temp_s2);
    func_00576788(arg1);
    M2C_FIELD(arg1, s32 *, 0x80) = 1;
    func_0057CB00(arg0 + 0x4C, arg1 + 0x3C);
    func_005767C0(arg1);
    func_00574EE8(arg0 + 0x64);
    func_005767C0(temp_s2);
}
