#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK AutomobileControlRecord__Recorder__finish(void *);                      /* extern */
void RaceBasic__cleanup();                            /* extern */

M2C_UNK RaceSolitaire__cleanup(void *arg0) {
    RaceBasic__cleanup();
    if ((u32) M2C_FIELD(arg0, u32 *, 0xCC8) < 2U) {
        AutomobileControlRecord__Recorder__finish(arg0 + 0xEFE8);
        AutomobileControlRecord__Recorder__finish(arg0 + 0xEF78);
    }
}
