/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
extern "C" int func_004A7C00(void);
struct Spr { char pad[0x138]; unsigned char r,g,b; char pad2[0x1D8-0x13B]; unsigned long bits; };
extern "C" int func_004A4050(unsigned int color) {
    struct Spr *p = (struct Spr *)spr_base();
    int result = func_004A7C00();
    unsigned long bits = p->bits | 0x800000000UL;
    p->r = color;
    unsigned int blue = color >> 16;
    color >>= 8;
    p->g = color;
    p->b = blue;
    p->bits = bits;
    return result;
}
