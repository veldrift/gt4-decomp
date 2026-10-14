/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_005A48D8(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

extern char D_008899E8[];
extern char D_0065833C[];
s32 func_005B2B88(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK arg4, M2C_UNK arg5, M2C_UNK arg6) {
    *(s32 *)D_0065833C = 0;
    func_005A48D8((s32)D_008899E8, 0, 4);
    return 0;
}
