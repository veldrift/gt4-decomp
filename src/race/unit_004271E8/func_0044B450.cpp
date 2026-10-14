#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_0044B680(s32, s32, s64 *, s64 *, s32); /* extern */

void func_0044B450(s32 arg0, s32 arg1, s32 arg2) {
    s64 sp;
    sp = 0;
    func_0044B680(arg0, arg1, &sp, &sp, arg2);
}

}
