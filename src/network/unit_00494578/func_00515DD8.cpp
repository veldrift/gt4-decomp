#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_0085E670[];

s32 func_00515DD8(u32 arg0) {
    if (arg0 < 0x1000U) {
        return D_0085E670[arg0];
    }
    return 0;
}
