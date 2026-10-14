/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00254FD0();                              /* extern */

void func_002681A8(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 0x90);
    if (var_v1 == NULL) {
        temp_v0 = func_00254FD0();
        M2C_FIELD(arg0, void **, 0x90) = temp_v0;
        var_v1 = temp_v0;
    }
    temp_v0_2 = var_v1 + 0x10;
    if (temp_v0_2 != arg1) {
        M2C_FIELD(var_v1, f32 *, 0x10) = (f32) M2C_FIELD(arg1, f32 *, 0);
        M2C_FIELD(temp_v0_2, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
        M2C_FIELD(temp_v0_2, f32 *, 8) = (f32) M2C_FIELD(arg1, f32 *, 8);
        M2C_FIELD(temp_v0_2, f32 *, 0xC) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
        var_v1 = M2C_FIELD(arg0, void **, 0x90);
    }
    M2C_FIELD(var_v1, s32 *, 0x20) = (s32) (M2C_FIELD(var_v1, s32 *, 0x20) | 2);
}
