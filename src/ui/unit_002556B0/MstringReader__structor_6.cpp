#include "types.h"
#define NULL 0

extern "C" s32 func_0024DB78(void *arg0, void *arg1);
extern "C" void func_0020FCE0(void *arg0, s32 arg1);
extern char D_00666CF0[];

void func_00261E70(void *arg0, s32 arg1) {
    s32 sp[4];
    s32 vt = (s32)D_00666CF0;
    sp[1] = arg1;
    sp[0] = vt;
    func_0024DB78(sp, arg0);
    sp[0] = vt;
    func_0020FCE0(sp, 0);
}
