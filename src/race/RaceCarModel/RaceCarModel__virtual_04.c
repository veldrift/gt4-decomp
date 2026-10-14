#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void HumanModel__virtual_02(void *);                      /* extern */
M2C_UNK func_00451200(s32);                         /* extern */

M2C_UNK RaceCarModel__virtual_04(void *arg0) {
    func_00451200(arg0 + 0x18);
    if (M2C_FIELD(arg0, s32 *, 0x1670) != 0) {
        HumanModel__virtual_02(arg0 + 0x5E0);
        if (M2C_FIELD(arg0, s32 *, 0x1674) != 0) {
            HumanModel__virtual_02(arg0 + 0xE20);
        }
    }
}
