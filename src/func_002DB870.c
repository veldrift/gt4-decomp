/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00208210();                            /* extern */
M2C_UNK func_0057CD90(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0057CE40(s32, M2C_UNK);                /* extern */

void func_002DB870(s32 arg0) {
    s32 temp_s0;

    func_00208210();
    temp_s0 = arg0 + 0xBC;
    func_0057CE40(temp_s0, 0);
    func_0057CD90(temp_s0, 0, 0);
}
