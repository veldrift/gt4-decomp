#include "types.h"

extern "C" void func_005DECE0(void *self, struct func_0026A540_node *x);

struct func_0026A540_node {
    s32 unk0;
    struct func_0026A540_node *unk4;
    struct func_0026A540_node *unk8;
    struct func_0026A540_node *unkC;
};

struct func_0026A540_ctl {
    s32 unk0;
    struct func_0026A540_node *unk4;
    struct func_0026A540_node *unk8;
};

extern "C" void func_0026A540(char *arg0) {
    struct func_0026A540_ctl *c = (struct func_0026A540_ctl *)(arg0 + 0x20);

    if (c->unk8 != 0) {
        func_005DECE0(c, c->unk4->unk4);
        c->unk4->unk8 = c->unk4;
        c->unk4->unk4 = 0;
        c->unk4->unkC = c->unk4;
        c->unk8 = 0;
    }
}
