/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00622F4C[];
void func_0010F880(void *arg0) {
    func_003C0C40(arg0, M2C_FIELD(*(void **)D_00622F4C, s32 *, 0x39D78) ^ 1, 0);
    func_003C0D78(arg0, 1, 0);
    func_003C0D98(arg0, 1, 0);
}
