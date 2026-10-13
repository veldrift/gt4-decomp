#include "types.h"

void func_002550A0(s32, s32);                   /* extern */
void func_002556B0();                           /* extern */
s32 func_005D9050(void *, s32);                 /* extern */

struct func_00213028_tree {
    s32 unk0;
    s32 unk4;
};

s32 func_00213028(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    s32 temp_v0;
    s32 temp_a1;
    struct func_00213028_tree *temp_s0;

    temp_s0 = (struct func_00213028_tree *)(arg1 + 0x10);
    temp_v0 = func_005D9050(temp_s0, arg2);
    sp[0] = temp_v0;
    temp_a1 = temp_v0 + 0x14;
    if (temp_v0 != temp_s0->unk4) {
        func_002550A0(arg0, temp_a1);
    } else {
        func_002556B0();
    }
    return arg0;
}
