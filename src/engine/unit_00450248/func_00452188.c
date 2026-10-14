#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00105250(void *);                      /* extern */
M2C_UNK func_00105280(void *, M2C_UNK);             /* extern */
M2C_UNK func_00107AE8(M2C_UNK *);                   /* extern */
M2C_UNK func_00107B00(M2C_UNK *, M2C_UNK);          /* extern */
s32 *func_00450FE0();                               /* extern */
M2C_UNK func_004517E0(void *);                      /* extern */
M2C_UNK func_004519A8(void *);                      /* extern */
M2C_UNK func_004519D8(void *);                      /* extern */
M2C_UNK func_004533A8(void *);                      /* extern */
M2C_UNK func_00453A28(s32, s32, void *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_00453A48(s32);                         /* extern */
M2C_UNK func_00455598(s32, M2C_UNK, s32 *);         /* extern */
M2C_UNK ModelSet2__registerExternalTexSet(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0049B448(M2C_UNK);                     /* extern */
M2C_UNK func_0049B478(M2C_UNK, f32);                /* extern */

void func_00452188(void *arg0, s32 arg1, s32 arg2) {
    struct StackFrame_00452188 { s8 pad0[0x40]; s32 sp40; s8 pad1[0x3C]; s32 sp80; s8 pad2[0x2C]; } sp_;
    s32 *temp_v0;
    s32 temp_s4;

    temp_s4 = arg0 + 0xC;
    temp_v0 = func_00450FE0();
    if (temp_v0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x174) = arg2;
        func_004517E0(arg0);
        func_00105250(((s8 *)&sp_));
        func_00107AE8(&sp_.sp40);
        func_00453A28(temp_s4, arg1, ((s8 *)&sp_), &sp_.sp40, &sp_.sp80);
        func_004519A8(arg0);
        func_0049B448(1);
        func_0049B478(2, 0x1.0000000000000p+0f);
        func_0049B478(4, 0x1.0000000000000p+0f);
        func_0049B478(3, M2C_FIELD(arg0, f32 *, 0x3C));
        if (M2C_FIELD(arg0, s32 *, 0x80) == 1) {
            func_004533A8(arg0);
        }
        func_00455598(*temp_v0, 0, temp_v0);
        func_0049B448(0);
        func_004519D8(arg0);
        func_00453A48(temp_s4);
        ModelSet2__registerExternalTexSet(3, 0);
        ModelSet2__registerExternalTexSet(2, 0);
        ModelSet2__registerExternalTexSet(1, 0);
        func_00107B00(&sp_.sp40, 2);
        func_00105280(((s8 *)&sp_), 2);
    }
}
