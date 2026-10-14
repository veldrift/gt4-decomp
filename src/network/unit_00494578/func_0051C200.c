#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */
s32 func_0051DB90(s32);                         /* extern */

s32 func_0051C200(s32 arg0) {
    if (func_0051BE28() == 0) {
        func_0051DB90(arg0);
        func_0051BE60();
        return 0;
    }
}
