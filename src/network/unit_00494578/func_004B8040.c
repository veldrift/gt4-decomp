#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s8 *func_004B8040(s8 *arg0) {
    void *temp_s0;
    void *temp_s0_2;

    temp_s0_2 = arg0 + ((1 - M2C_FIELD(arg0, s32 *, 0x858)) * 0x41C);
    func_004B5FE0(arg0);
    temp_s0 = temp_s0_2 + 0x20;
    func_004B9820(M2C_FIELD(temp_s0, s8 **, 0xC), M2C_FIELD(temp_s0, u16 **, 8));
    return M2C_FIELD(temp_s0, s8 **, 0xC);
}
