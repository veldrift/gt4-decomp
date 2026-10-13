#include "types.h"
#define NULL 0

extern "C" char *func_005C2560(void *);

struct func_00268888_arg1 {
    char pad0[0x94];
    s8 *unk94;
};

struct func_00268888_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s8 **func_00268888(s8 **arg0, struct func_00268888_arg1 *arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct func_00268888_temp_a1 *temp_a1;

    temp_v0 = arg1->unk94;
    temp_a1 = (struct func_00268888_temp_a1 *)(temp_v0 - 0x10);
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = (s8 *)func_005C2560(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    *arg0 = var_a2;
    return arg0;
}
