#include "types.h"

extern char D_00645570[];

extern "C" void RaceBase__postInitialize(void *self);
extern "C" void CarIconMaker__structor_1(void *owner, s32 src);
extern "C" void func_004FAF50(void *g);

extern "C" void RaceNetBattle__virtual_39(char *arg0) {
    char *g;

    RaceBase__postInitialize(arg0);
    CarIconMaker__structor_1(arg0 + 0x1E7A8, *(s32 *)(arg0 + 0x6C));
    g = D_00645570;
    *(s32 *)(arg0 + 0x1ED24) = 0;
    func_004FAF50(g);
    *(s32 *)(arg0 + 0x22C4C) = *(s32 *)(g + 0xFD8);
}
