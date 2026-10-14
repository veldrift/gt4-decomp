/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004472A0(s32);                             /* extern */
s32 SPEC_DATABASE__RaceSpec__getBronzeTime(s32);                             /* extern */
s32 SPEC_DATABASE__RaceSpec__getGoldTime(s32);                             /* extern */
s32 SPEC_DATABASE__RaceSpec__getSilverTime(s32);                             /* extern */
M2C_UNK func_005A609C(void *, s32);                 /* extern */

extern char D_00622F4C[];
void func_00115310(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x4B4) = 1;
    M2C_FIELD(arg0, s32 *, 0x46C) = 0;
    M2C_FIELD(arg0, s32 *, 0x470) = 0;
    M2C_FIELD(arg0, s32 *, 0x474) = 0;
    func_005A609C(arg0 + 0x3C8, *(s32 *)D_00622F4C + 0x46);
    func_005A609C(arg0 + 0x408, func_004472A0(M2C_FIELD(M2C_FIELD(arg1, void **, 0x6C), s32 *, 0x70)));
    M2C_FIELD(arg0, s32 *, 0x448) = SPEC_DATABASE__RaceSpec__getBronzeTime(M2C_FIELD(M2C_FIELD(arg1, void **, 0x6C), s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x44C) = SPEC_DATABASE__RaceSpec__getGoldTime(M2C_FIELD(M2C_FIELD(arg1, void **, 0x6C), s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x450) = SPEC_DATABASE__RaceSpec__getSilverTime(M2C_FIELD(M2C_FIELD(arg1, void **, 0x6C), s32 *, 0x70));
}
