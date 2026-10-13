#include "types.h"

void func_0025B460(void *c, f32 x, f32 y);      /* extern */

struct func_002B2188_arg0 {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[0x11C - 0xB4];
    void *unk11C;
};

void func_002B2188(struct func_002B2188_arg0 *arg0, f32 fparg0, f32 fparg1) {
    if (arg0->unkB0 == 0) {
        return func_0025B460(arg0->unk11C, fparg0, fparg1);
    }
    func_0025B460(arg0->unk11C, fparg1, fparg0);
}
