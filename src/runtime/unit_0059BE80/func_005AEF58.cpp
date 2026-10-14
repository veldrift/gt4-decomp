#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADCD0(s32);                         /* extern */

s32 func_005AEF58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_005ADCD0(arg3);
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 0;
}
