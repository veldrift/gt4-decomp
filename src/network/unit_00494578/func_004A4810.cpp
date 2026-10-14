#include "spr.h"
typedef unsigned long long u64;
struct Scissor { u64 low:4, x0:10, y0:10, x1:10, y1:10, high:20; };
struct Spr { char pad[0x1a8]; Scissor sc; char pad2[0x28]; u64 flags; };
extern "C" void func_004A4810(int mode, unsigned int x, unsigned int y) {
 Spr *p=(Spr *)spr_base();
 switch(mode) {
 case 0: { p->sc.x0=x; p->sc.y0=y; p->flags |= 0x800080; return; }
 case 1: { p->sc.x1=x; p->sc.y1=y; p->flags |= 0x800080; return; }
 }
}
