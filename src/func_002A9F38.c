#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_0028EAC8();                            /* extern */
M2C_UNK func_005D4AD8(M2C_UNK, s32, s32, s32, s32, s32); /* extern */

extern char D_0069BBC8[];
s32 func_002A9F38(void *arg0) {
    s32 temp_a2;

    func_0028EAC8();
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x24);
    func_005D4AD8((s32)D_0069BBC8, M2C_FIELD(arg0, s32 *, 0x20), temp_a2, temp_a2 & 0xF, (s32) M2C_FIELD(arg0, f32 *, 0x28), (s32) M2C_FIELD(arg0, f32 *, 0x2C));
    return 0;
}
