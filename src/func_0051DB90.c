#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_0051D060(s32);                         /* extern */
void func_0051D8E0(s32);                         /* extern */
s32 func_0051DCF8(s32);                             /* extern */
s32 func_0051DD50();                                /* extern */
M2C_UNK func_00538C68(s32);                         /* extern */

extern char D_0064AE14[];
extern char D_0064B710[];
void func_0051DB90(s32 arg0) {
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    u32 var_s1;
    void *temp_v0_2;

    temp_v0 = func_0051DD50();
    if (temp_v0 != 0) {
        if (func_0051DCF8(arg0) != 0) {
            func_0051D060(arg0);
        }
        var_s1 = 0;
        var_s0 = temp_v0 + 0x78;
        do {
            temp_a0 = *var_s0;
            var_s0 += 1;
            var_s1 += 1;
            func_0051D8E0(temp_a0);
        } while (var_s1 < 2U);
        func_00538C68(temp_v0 + 0x38);
        func_00538C68(*(s32 *)D_0064AE14 + (arg0 * 4));
        temp_v0_2 = *(void **)D_0064B710;
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32), 0x5C)(arg0 & 0x7FFFFFFF);
        }
    }
}
