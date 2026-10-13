#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
M2C_UNK func_001BF598(s32 *, M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_001C58D8(s32);                         /* extern */

void func_001BF058(s32 *arg0) {
    void *temp_v0;

    func_001BF598(arg0, 0, 0);
    func_001C58D8(M2C_FIELD(arg0, s32 *, 0x14));
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    temp_v0 = M2C_FIELD(arg0, void **, 4);
    ({ VEntry *e1_ = (VEntry *)((char *)temp_v0 + 0x2B0); ((void (*)(void *))e1_->fn)((char *)arg0 + e1_->delta); });
}
