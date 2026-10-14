#include "spr.h"
struct S { char pad0[0x1a0]; long flags; char pad1[0x30]; long flags2; };
void func_004A2858(int a) {
 S *p=(S *)spr_base();
 if (a == 5) p->flags |= 0x8000;
 else if (a == 2) p->flags &= ~0x8000;
 p->flags2 |= 0x400040;
}
