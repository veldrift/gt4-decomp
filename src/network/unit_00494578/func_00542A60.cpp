#include "types.h"
#define NULL 0

struct func_00542A60_node {
    struct func_00542A60_node *unk0;
    struct func_00542A60_node *unk4;
};

struct func_00542A60_arg0 {
    char pad0[0x8];
    struct func_00542A60_node *unk8;
    struct func_00542A60_node *unkC;
};

void func_00542A60(struct func_00542A60_arg0 *arg0, struct func_00542A60_node *arg1) {
    struct func_00542A60_node *temp_v1;
    struct func_00542A60_node *temp_v0;
    struct func_00542A60_node *temp_v1_2;
    struct func_00542A60_node *temp_v0_2;

    if (arg0 != NULL && arg1 != NULL) {
        if ((temp_v1 = arg1->unk4) != NULL) {
            temp_v1->unk0 = arg1->unk0;
        } else {
            arg0->unkC = arg1->unk0;
        }
        temp_v0_2 = arg1->unk4;
        temp_v1_2 = arg1->unk0;
        if (temp_v1_2 != NULL) {
            temp_v1_2->unk4 = temp_v0_2;
            return;
        }
        arg0->unk8 = temp_v0_2;
    }
}
