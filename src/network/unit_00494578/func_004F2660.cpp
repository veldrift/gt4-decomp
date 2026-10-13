#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88(void *);                          /* extern */
s32 func_004F0CD0(void *, s32);                     /* extern */
s32 func_005A48D8(void *, s32, s32);                /* extern */

struct func_004F2660_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};

struct func_004F2660_temp_a0 {
    char pad0[0x16];
    s16 unk16;
    s16 unk18;
};

s32 func_004F2660(struct func_004F2660_arg0 *arg0, s32 arg1, s32 arg2) {
    void *temp_a0;
    s32 r;

    r = func_004F0C88(arg0);
    if (r != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x1A);
        temp_a0 = arg0->unk5A8;
        arg2 = arg2 >= 0x11 ? 0x10 : arg2;
        ((struct func_004F2660_temp_a0 *)temp_a0)->unk16 = arg1;
        ((struct func_004F2660_temp_a0 *)temp_a0)->unk18 = arg2;
        return func_004F0CD0(arg0, 0x17);
    }
    return r;
}
