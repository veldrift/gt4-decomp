#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005018D0(s32, s32);                    /* extern */
s32 *func_00501980(s32, s32);                  /* extern */
s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */

void func_00501870(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 *temp_v0;

    sp[0] = (s32)(arg0 + 8);
    func_00576788(sp[0]);
    temp_v0 = func_00501980(arg0, arg1);
    if (temp_v0 != NULL) {
        func_005018D0(arg0, *temp_v0);
    }
    func_005767C0(sp[0]);
}
