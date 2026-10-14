#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00538A58(s8 *arg0, u32 arg1) {
    s8 *var_a0;
    u32 temp_v0;
    u32 temp_v0_2;
    u32 var_a1;
    u32 var_a5;
    u32 var_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a0 != NULL) {
        var_a5 = 0;
        do {
            if (var_a5 != 0) {
                *var_a0 = 0x2E;
                var_a0 += 1;
            }
            var_v1 = var_a1 & 0xFF;
            var_a1 = var_a1 >> 8;
            if (var_v1 >= 0x64U) {
                temp_v0 = var_v1 / 100U;
                *var_a0 = temp_v0 + 0x30;
                var_a0 += 1;
                var_v1 = var_v1 % 100U;
                goto block_7;
            }
            if (var_v1 >= 0xAU) {
block_7:
                temp_v0_2 = var_v1 / 10U;
                var_v1 = var_v1 % 10U;
                *var_a0 = temp_v0_2 + 0x30;
                var_a0 += 1;
            }
            var_a5 += 1;
            *var_a0 = var_v1 + 0x30;
            var_a0 += 1;
        } while (var_a5 < 4U);
        *var_a0 = 0;
    }
}
