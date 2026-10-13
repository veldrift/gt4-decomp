#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_005659D8();                            /* extern */
M2C_UNK func_005A48D8(void *, M2C_UNK, M2C_UNK);    /* extern */

extern char D_008A1B00[];
extern char D_00689CD8[];
void func_00566DA8(void *arg0) {
    func_005659D8();
    M2C_FIELD(arg0, s32 *, 0x18) = 5;
    M2C_FIELD(arg0, s32 *, 0x68) = (s32)D_00689CD8;
    *(void **)D_008A1B00 = arg0;
    func_005A48D8(arg0 + 0x6C, 0, 0x10);
}
