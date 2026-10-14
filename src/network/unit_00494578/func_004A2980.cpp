#include "spr.h"
struct Spr { char pad[0x174]; int value; char pad2[0x1D8-0x178]; long long flags; };
extern "C" void func_004A2980(int arg) {
    Spr *p = (Spr *)spr_base();
    p->value = ~arg;
    p->flags |= 0x10001LL;
}
