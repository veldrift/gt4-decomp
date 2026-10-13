/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
M2C_UNK func_003744C0(s32, s32);                    /* extern */
M2C_UNK func_003889E0();                            /* extern */

void func_00336D90(s32 *arg0) {
    void *temp_v1;

    func_003889E0();
    temp_v1 = M2C_FIELD(arg0, void **, 0x64);
    func_003744C0(({ VEntry *e1_ = (VEntry *)((char *)temp_v1 + 0xD0); ((s32 (*)(void *, M2C_UNK))e1_->fn)((char *)arg0 + e1_->delta, 0); }), M2C_FIELD(arg0, s32 *, 0xE444));
}
