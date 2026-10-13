#include "types.h"
#define NULL 0

s32 func_005A48D8(s32, s32, s32);   /* extern */

extern char D_0064A318[];
extern s32 D_0064A308;
extern s16 D_0064A310;

s32 func_0050B410(void) {
    s32 *p;

    func_005A48D8((s32)D_0064A318, 0, 0x11);
    p = &D_0064A308;
    if (*p != 1) {
        return -0xF;
    }
    *p = 0;
    D_0064A310 = 0;
    return 0;
}
