#include "types.h"
#define NULL 0

extern "C" s32 *func_0021B788(s32 arg0);
extern "C" char *func_005C2560(void *);

struct func_0013A370_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 *func_0013A370(s32 *arg0, s32 arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct func_0013A370_temp_a1 *temp_a1;

    temp_v0 = (s8 *) *func_0021B788(arg1 + 0xA0);
    temp_a1 = (struct func_0013A370_temp_a1 *) (temp_v0 - 0x10);
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = (s8 *) func_005C2560(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    *arg0 = (s32) var_a2;
    return arg0;
}
