#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
void func_002797F8(void *arg0, s32 *arg1) {
    void *temp_v0;

    M2C_FIELD(arg0, void **, 0x14) = arg1;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 4);
        M2C_FIELD(arg0, f32 *, 0x1C) = ({ VEntry *e1_ = (VEntry *)((char *)temp_v0 + 0x1C0); ((f32 (*)(void *))e1_->fn)((char *)arg1 + e1_->delta); });
    }
}
