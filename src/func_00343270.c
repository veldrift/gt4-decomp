#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
M2C_UNK func_003DF978();                            /* extern */
s32 func_004FB168(M2C_UNK);                         /* extern */

extern char D_00645570[];
void func_00343270(s32 *arg0, s32 arg1) {
    f32 temp_f0;
    void *temp_v0;

    func_003DF978();
    if (M2C_FIELD(arg0, s32 *, 0x504) != 0) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x500) - 0.016666666f;
        M2C_FIELD(arg0, f32 *, 0x500) = temp_f0;
        if ((temp_f0 < 0.0f) && (M2C_FIELD(arg0, s32 *, 0) == 0)) {
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            ({ VEntry *e1_ = (VEntry *)((char *)temp_v0 + 0x38); ((void (*)(void *, s32))e1_->fn)((char *)arg0 + e1_->delta, arg1); });
        }
    } else if (func_004FB168((s32)D_00645570) != 0) {
        M2C_FIELD(arg0, s32 *, 0x504) = 1;
    }
}
