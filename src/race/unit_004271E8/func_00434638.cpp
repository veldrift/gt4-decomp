#include "types.h"
#define NULL 0

extern s8 *D_00622F4C;
void func_00434950(void *);

struct func_00434638_arg0 {
    char pad0[0x48];
    s32 unk48;
    char pad4C[0x4];
    s32 unk50;
    s32 unk54;
    char pad58[0x8];
    s32 unk60;
    char pad64[0x8];
    s32 unk6C;
};

void func_00434638(struct func_00434638_arg0 *arg0) {
    arg0->unk54 = arg0->unk50;
    if (arg0->unk60 != 0) {
        arg0->unk48 = 0;
        func_00434950(arg0);
        arg0->unk6C = *(s32 *)(D_00622F4C + 0x39E1C) - 1;
    }
}
