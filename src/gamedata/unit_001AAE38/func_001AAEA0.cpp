#include "types.h"
#include "m2c_macros.h"
extern "C" s32 func_001AAE38(s32, M2C_UNK);
extern "C" M2C_UNK func_001C6D78(void *, M2C_UNK);
extern "C" s32 func_001C6DB8(void *);
extern "C" s32 func_001C6DC8(void *);
extern "C" s32 func_001C6E78(void *, s32);

extern "C" void func_001AAEA0(void *arg0) {
    s32 temp_v0;
    void *temp_s0;

    temp_s0 = (char *)arg0 + 0xBC;
    if (func_001C6DB8(temp_s0) == 0) {
        s32 one = 1;
loop_1:
        temp_v0 = func_001C6E78(temp_s0, M2C_FIELD(temp_s0, s32 *, 4));
        if (temp_v0 != 0) {
            if (temp_v0 <= 0) {
                if (temp_v0 >= -2) {
                    goto block_7;
                }
                goto block_8;
            }
            if (temp_v0 == one) {
block_7:
                func_001C6D78(temp_s0, 1);
                if (func_001C6DB8(temp_s0) == 0) {
                    goto block_8;
                }
                goto loop_11;
            }
            goto block_9;
        }
block_8:
block_9:
        if (func_001AAE38((s32)arg0, 1) == 0) {
            return;
        }
        goto loop_1;
    }
loop_11:
    if (func_001C6DC8(temp_s0) == 0) {
        if (func_001AAE38((s32)arg0, 1) != 0) {
            goto loop_11;
        }
    }
}
