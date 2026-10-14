#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK RaceEntryCar__setPlayerSpec(s32, void *);                 /* extern */
M2C_UNK func_003D6268(void *);                      /* extern */
M2C_UNK func_003D62A8(void *, M2C_UNK);             /* extern */
M2C_UNK RacePlayerSpec__createEquipments(void *, s64, M2C_UNK, M2C_UNK); /* extern */

void RaceArcadeDemoInformation__updateEntryCar(void *arg0, s32 arg1) {
    struct StackFrame_00387750 { s8 pad0[0x190]; } sp_;
    if (M2C_FIELD(arg0, s64 *, 0x2C0) != 0) {
        func_003D6268(((s8 *)&sp_));
        RacePlayerSpec__createEquipments(((s8 *)&sp_), M2C_FIELD(arg0, s64 *, 0x2C0), -1, 1);
        RaceEntryCar__setPlayerSpec(arg1, ((s8 *)&sp_));
        func_003D62A8(((s8 *)&sp_), 2);
    }
}
