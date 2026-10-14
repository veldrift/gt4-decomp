#include "spr.h"
typedef unsigned char u8;
typedef signed char s8;
struct Spr { char pad0[0xEB]; u8 xEB; char padEC[0x2C0-0xEC]; s8 x2C0; u8 x2C1; };
extern "C" long func_004A7C60() {
    Spr *p = (Spr *)spr_base();
    if (p->xEB != 1) return 0;
    if (p->x2C1 != 0) return 9;
    return p->x2C0 == 0 ? 3 : 4;
}
