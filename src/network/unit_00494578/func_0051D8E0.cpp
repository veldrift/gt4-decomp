/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" s32 func_00538068(void *arg0);
extern "C" s32 func_00538C68(s32 *arg0);

extern "C" void func_0051D8E0(s32 arg0) {
    if (arg0 != 0) {
        func_00538068((char *)arg0 + 0x54);
        func_00538068((char *)arg0 + 0x6C);
        func_00538C68(&arg0);
    }
}
