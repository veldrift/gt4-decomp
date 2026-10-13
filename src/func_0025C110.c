/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005C0FC8(s32, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *); /* extern */

extern char D_005DAD50[];
extern char D_005DEA30[];
s32 func_0025C110(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v1;

    var_v1 = arg0;
loop_1:
    temp_v0_2 = M2C_FIELD(var_v1, void **, 0x54);
    if (temp_v0_2 != NULL) {
        var_v1 = temp_v0_2;
        goto loop_1;
    }
    if (var_v1 != NULL) {
        temp_v0 = M2C_FIELD(var_v1, void **, 4);
        return func_005C0FC8(M2C_FIELD(temp_v0, s32 *, 4), (s32)D_005DAD50, 0, var_v1 + M2C_FIELD(temp_v0, s16 *, 0), (s32)D_005DEA30, var_v1);
    }
    return 0;
}
