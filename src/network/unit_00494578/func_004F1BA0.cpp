#include "types.h"

extern "C" {
s32 func_004F0C88(void *arg0);                      /* extern */
s32 func_004F0CD0(void *arg0, s32 arg1);            /* extern */
s32 func_005A48D8(s32, s32, s32);                   /* extern */
}

struct Blk48 {
    s32 w[12];
};

struct func_004F1BA0_arg0 {
    char pad0[0x5A8];
    Blk48 *unk5A8;
};

extern "C" s32 func_004F1BA0(void *arg0, void *arg1) {
    struct func_004F1BA0_arg0 *a = (struct func_004F1BA0_arg0 *)arg0;
    s32 r = func_004F0C88(arg0);

    if (r != 0) {
        func_005A48D8((s32)a->unk5A8, 0, 0x30);
        *a->unk5A8 = *(Blk48 *)arg1;
        return func_004F0CD0(arg0, 9);
    }
    return r;
}
