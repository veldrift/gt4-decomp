/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00645570[];
struct RaceNetRallyBattle {
    char unk_0[0x58];
    s32 unk58;
    char unk_5C[0x8];
    void * unk64;
    char unk_68[0x4];
    void * unk6C;
    s32 unk70;
    void * unk74;
    void * unk78;
    char unk_7C[0xC44];
    s32 unkCC0;
    s32 unkCC4;
    s32 unkCC8;
    s32 unkCCC;
    s32 unkCD0;
    s32 unkCD4;
    s32 unkCD8;
    s32 unkCDC;
    s32 unkCE0;
    char unk_CE4[0x30];
    s32 unkD14;
    s32 unkD18;
    s32 unkD1C;
    s32 unkD20;
    s32 unkD24;
    s32 unkD28;
    void * unkD2C;
    char unk_D30[0x4];
    f32 unkD34;
    s32 unkD38;
    f32 unkD3C;
    char unk_D40[0x4];
    s32 unkD44;
    s32 unkD48;
    s32 unkD4C;
    s32 unkD50;
    s32 unkD54;
    s32 unkD58;
    s32 unkD5C;
    s32 unkD60;
    s32 unkD64;
    s32 unkD68;
    s32 unkD6C;
    char unk_D70[0x10];
    s32 unkD80;
    s32 unkD84;
    s32 unkD88;
    s32 unkD8C;
    s32 unkD90;
    s32 unkD94;
    s32 unkD98;
};
s32 func_0034C190(s32, s32);
s32 func_004F9368(M2C_UNK, s32);                    /* extern */

s32 RaceNetRallyBattle__virtual_41(struct RaceNetRallyBattle *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v0;
    void *temp_v0;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x22C38);
    if (var_v0 == 0) {
        M2C_FIELD(arg0, s32 *, 0x22C38) = 1;
        temp_v0 = func_0034C190(M2C_FIELD(M2C_FIELD(arg0->unk6C, void **, 0x84), s32 *, 0x70), arg1);
        var_a1 = 0x157529FF;
        if (M2C_FIELD(temp_v0, u8 *, 0x5B6) != 0) {
            var_a1 = M2C_FIELD(temp_v0, s32 *, 0x718);
        }
        var_v0 = func_004F9368((s32)D_00645570, var_a1);
    }
    return var_v0;
}
