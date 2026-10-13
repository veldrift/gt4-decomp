#include "types.h"

extern "C" void func_0060D830(void *, void *);

struct func_004E73B0_node {
    s32 unk0;
    struct func_004E73B0_node *unk4;
    struct func_004E73B0_node *unk8;
    struct func_004E73B0_node *unkC;
};

struct func_004E73B0_ctl {
    s32 unk0;
    struct func_004E73B0_node *unk4;
    struct func_004E73B0_node *unk8;
};

extern "C" void func_004E73B0(char *arg0) {
    struct func_004E73B0_ctl *c = (struct func_004E73B0_ctl *)(arg0 + 0x58);

    if (c->unk8 != 0) {
        func_0060D830(c, c->unk4->unk4);
        c->unk4->unk8 = c->unk4;
        c->unk4->unk4 = 0;
        c->unk4->unkC = c->unk4;
        c->unk8 = 0;
    }
}
