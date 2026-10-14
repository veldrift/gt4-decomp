#include "spr.h"
struct Spr { char p[0x198]; char x; char p1[3]; char y; char p2[0x1d8-0x19d]; long long flags; };
extern "C" void func_004A2908(int a, int b) {
    Spr *p = (Spr *)spr_base();
    long long m = 0x200020;
    long long f = p->flags;
    p->x = a;
    p->y = b;
    p->flags = f | m;
}
