/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00201700();                            /* extern */
void *func_005C0FC8(s32, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *); /* extern */

extern char D_005E86A0[];
extern char D_005EFF90[];
void func_002B8F88(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    func_00201700();
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 4);
        var_v1 = func_005C0FC8(M2C_FIELD(temp_v0, s32 *, 4), (s32)D_005E86A0, 0, arg1 + M2C_FIELD(temp_v0, s16 *, 0), (s32)D_005EFF90, arg1);
    }
    if (var_v1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0xC0) = (s32) M2C_FIELD(var_v1, s32 *, 0xC0);
        M2C_FIELD(arg0, f32 *, 0xC4) = (f32) M2C_FIELD(var_v1, f32 *, 0xC4);
        M2C_FIELD(arg0, f32 *, 0xC8) = (f32) M2C_FIELD(var_v1, f32 *, 0xC8);
    }
}
