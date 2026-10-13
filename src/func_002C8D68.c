#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002319C0(s32);                             /* extern */
s32 func_00235C80(s32, s32);                /* extern */
s32 func_002C8180(void *);                          /* extern */

struct func_002C8D68_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

s32 func_002C8D68(struct func_002C8D68_arg0 *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unkC4 == 0) {
        return 0;
    }
    temp_s0 = func_002319C0(arg1);
    temp_v0 = func_002C8180(arg0);
    if (temp_v0 != 0) {
        func_00235C80(temp_s0, temp_v0);
    }
    return temp_v0;
}
