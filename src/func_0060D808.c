#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004CBE08(void *, s32, s32, s32);       /* extern */

void func_0060D808(void *arg0, s32 arg1, s32 arg2) {
    func_004CBE08(arg0, M2C_FIELD(arg0, s32 *, 0x7C), arg1, arg2);
}
