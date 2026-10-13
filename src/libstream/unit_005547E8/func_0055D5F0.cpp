#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0055D5F0_temp_a2 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct func_0055D5F0_arg0 {
    char pad0[0x24];
    s8 unk24;
    char pad25[0xB];
    s32 unk30;
    char pad34[0x98];
    s32 unkCC;
};

void func_0055D5F0(void *arg0, s32 arg1) {
    s32 var_a1;
    s8 var_a3;
    struct func_0055D5F0_temp_a2 *temp_a2;

    var_a1 = arg1;
    temp_a2 = (struct func_0055D5F0_temp_a2 *) ((char *) arg0 + 0xCC);
    if (((struct func_0055D5F0_arg0 *) arg0)->unk30 == 1) {
        var_a1 = arg1 * 2;
    }
    var_a3 = 0;
    temp_a2->unk4 = var_a1;
    if ((var_a1 != 0) && (temp_a2->unk8 != 0)) {
        var_a3 = temp_a2->unk0 != 0;
    }
    ((struct func_0055D5F0_arg0 *) arg0)->unk24 = var_a3;
}
