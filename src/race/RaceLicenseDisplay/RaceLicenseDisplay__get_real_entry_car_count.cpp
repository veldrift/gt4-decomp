#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" s32 Automobile__getDrawMode(s32);                             /* extern */

extern "C" s32 RaceLicenseDisplay__get_real_entry_car_count(M2C_UNK arg0, void *arg1) {
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    temp_s2 = *M2C_FIELD(arg1, s32 **, 0x60);
    var_s1 = 0;
    if (temp_s2 > 0) {
        do {
        temp_v0 = var_s0 * 4;
        var_s0 += 1;
        if (Automobile__getDrawMode(M2C_FIELD(*(s32 *)(temp_v0 + M2C_FIELD(M2C_FIELD(arg1, s32 **, 0x60), s32 *, 8)), s32 *, 0x18)) == 3) var_s1 += 1;
        } while (var_s0 < temp_s2);
    }
    return var_s1;
}
