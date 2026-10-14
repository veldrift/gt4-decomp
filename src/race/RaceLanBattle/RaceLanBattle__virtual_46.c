/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
M2C_UNK CameraSys__CameraManager__setTargetCar(s32, s32);                    /* extern */
M2C_UNK RaceBase__initializeCamera();                            /* extern */

void RaceLanBattle__virtual_46(s32 *arg0) {
    void *temp_v1;

    RaceBase__initializeCamera();
    temp_v1 = M2C_FIELD(arg0, void **, 0x64);
    CameraSys__CameraManager__setTargetCar(({ VEntry *e1_ = (VEntry *)((char *)temp_v1 + 0xD0); ((s32 (*)(void *, M2C_UNK))e1_->fn)((char *)arg0 + e1_->delta, 0); }), M2C_FIELD(arg0, s32 *, 0xE444));
}
