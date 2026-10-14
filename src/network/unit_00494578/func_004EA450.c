#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

char * strobe__toUpper(void *);
s8 **func_004EA450(s8 **arg0, void *arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    void *temp_a1;

    temp_v0 = M2C_FIELD(arg1, s8 **, 0x54);
    temp_a1 = temp_v0 - 0x10;
    var_a2 = temp_v0;
    if (M2C_FIELD(temp_a1, s32 *, 0xC) != 0) {
        var_a2 = strobe__toUpper(temp_a1);
    } else {
        M2C_FIELD(temp_a1, s32 *, 8) = (s32) (M2C_FIELD(temp_a1, s32 *, 8) + 1);
    }
    *arg0 = var_a2;
    return arg0;
}
