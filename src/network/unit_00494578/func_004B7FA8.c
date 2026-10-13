#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004B98F0(const u16 *);
s32 func_004B7FA8(void *arg0, s8 *arg1, s32 arg2) {
    void *temp_s1;

    temp_s1 = arg0 + ((1 - M2C_FIELD(arg0, s32 *, 0x858)) * 0x41C) + 0x20;
    func_004B5FE0(arg0);
    if (func_004B98F0(M2C_FIELD(temp_s1, u16 **, 8)) >= arg2) {
        *arg1 = 0;
        return 0;
    }
    func_004B9820(arg1, M2C_FIELD(temp_s1, u16 **, 8));
    return 1;
}
