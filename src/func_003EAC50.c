#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00346498(void *);                      /* extern */
void func_0038A9B8();                            /* extern */

M2C_UNK func_003EAC50(void *arg0) {
    func_0038A9B8();
    if ((u32) M2C_FIELD(arg0, u32 *, 0xCC8) < 2U) {
        func_00346498(arg0 + 0xEFE8);
        func_00346498(arg0 + 0xEF78);
    }
}
