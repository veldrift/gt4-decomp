#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00538460(void *, s32, s32);            /* extern */

struct func_00538418_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00538418(struct func_00538418_arg0 *arg0, s32 arg1) {
    if (arg0 == 0) {
        return 2;
    }
    if ((arg1 != 0) && (arg0->unk14 == 0)) {
        return 0xC9;
    }
    return func_00538460(arg0, arg1, arg0->unk14);
}
