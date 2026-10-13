#include "types.h"
#define NULL 0

extern "C" s32 func_00538C68(s32 *arg0);        /* extern */

struct func_00512350_obj {
    char pad0[0xC];
    u32 unkC;
    u32 unk10;
    s32 unk14;
    void (*unk18)(s32);
};

struct func_00512350_node {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 func_00512350(void *arg0, s32 *arg1) {
    struct func_00512350_obj *o = (struct func_00512350_obj *)arg0;
    u32 base;

    if (o->unk18 != NULL) {
        o->unk18(*arg1);
    }
    if (arg1 != NULL) {
        base = o->unk10;
        if ((u32)arg1 < base || (u32)arg1 >= base + o->unkC) {
            func_00538C68((s32 *)&arg1);
        } else {
            ((struct func_00512350_node *)arg1)->unk8 = o->unk14;
            o->unk14 = (s32)arg1;
        }
    }
    return 0;
}
