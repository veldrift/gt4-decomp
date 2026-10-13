#include "types.h"

struct func_00511FB8_entry {
    s32 unk0;
    s32 unk4;
};

struct func_00511FB8_inner {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[4];
    s32 unk44;
    char *unk48;
    s32 (*unk4C)(s32, s32, s32);
};

struct func_00511FB8_arg0 {
    char pad0[0x18];
    struct func_00511FB8_inner *unk18;
    char pad1C[4];
    s32 unk20;
    s32 unk24;
};

s32 func_00511FB8(struct func_00511FB8_arg0 *arg0, s32 *arg1) {
    struct func_00511FB8_inner *s0;
    s32 r;
    s32 temp;

    s0 = arg0->unk18;
    r = s0->unk4C(s0->unk3C, *arg1, s0->unk44);
    temp = ((struct func_00511FB8_entry *)(r * 8 + s0->unk48))->unk4;
    arg0->unk24 = temp;
    if (temp != 0) {
        arg0->unk20 = r;
        return 0;
    }
    return 4;
}
