#include "types.h"
#define NULL 0

extern char D_00697E90[];

s32 func_0021C5A8(s32, s32);
void func_0021C9D8(void *);
int func_002208E8(char *, unsigned, const char *, const char *);
void *func_004AE370(void *, char *, s32 *, s32);
void func_004AE6B0(void *, char *);
s32 malloc(s32);

struct func_0021CFC8_arg0 {
    char pad0[0x28];
    s32 unk28;
};

s32 func_0021CFC8(struct func_0021CFC8_arg0 *arg0, const char *arg1) {
    char sp[0x80];
    s32 sp80[8];
    s32 spA0[4];
    s32 spB0;
    char spB4[0x10];
    s32 temp_v0;
    s32 *pA0;
    s32 sp88;

    if (arg0->unk28 != 0) {
        func_0021C9D8(arg0);
    }
    func_002208E8(sp, 0x80, arg1, D_00697E90);
    func_004AE6B0(sp80, sp);
    sp88 = sp80[2];
    pA0 = spA0;
    pA0[0] = 0;
    pA0[1] = sp88;
    spA0[0] = malloc(sp88);
    func_004AE370(&spB0, sp, pA0, 1);
    if (spB0 != 0) {
        return 0;
    }
    arg0->unk28 = spA0[0];
    temp_v0 = func_0021C5A8(spA0[0], spA0[0]);
    if (temp_v0 == 0) {
        func_0021C9D8(arg0);
    }
    return temp_v0;
}
