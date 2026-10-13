#include "types.h"
#define NULL 0

void func_004ACE08(void *item);                 /* extern */
void func_00574DA8(void *, s32);                /* extern */
void func_0057CA38(void *, s32);                /* extern */
void func_005C1628(void *);                     /* extern */

extern char D_00688D48[];
extern char D_00688C40[];

struct func_004AD240_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

struct func_004AD240_sub {
    char pad0[8];
    s32 unk8;
};

void func_004AD240(void *arg0, s32 arg1) {
    struct func_004AD240_sub *temp_v0;
    struct func_004AD240_sub *temp_a0;
    struct func_004AD240_sub *temp_a0_2;

    ((struct func_004AD240_arg0 *)arg0)->unkA4 = (s32)D_00688D48;
    func_004ACE08(arg0);
    func_00574DA8((char *)arg0 + 0x64, 2);
    temp_v0 = (struct func_004AD240_sub *)((char *)arg0 + 0x58);
    temp_v0->unk8 = (s32)D_00688C40;
    func_0057CA38(temp_v0, 0);
    temp_a0 = (struct func_004AD240_sub *)((char *)arg0 + 0x4C);
    temp_a0->unk8 = (s32)D_00688C40;
    func_0057CA38(temp_a0, 0);
    temp_a0_2 = (struct func_004AD240_sub *)((char *)arg0 + 0x40);
    temp_a0_2->unk8 = (s32)D_00688C40;
    func_0057CA38(temp_a0_2, 0);
    func_00574DA8((char *)arg0 + 0x10, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
