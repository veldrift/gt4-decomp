#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00448DF0(s32);                         /* extern */

struct func_00436BE0_arg0 {
    char pad0[0x115C];
    s32 unk115C;
};

s32 func_00436BE0(struct func_00436BE0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk115C;
    if (temp_v0 == 0) {
        return (s32)"";
    }
    return func_00448DF0(temp_v0);
}
