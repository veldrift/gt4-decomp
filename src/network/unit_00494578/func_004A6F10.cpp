#include "spr.h"
struct Spr { char pad[0x248]; unsigned int value; };
extern "C" Spr *func_004A6F10(int x, unsigned int y) {
    if (x < 0) x = 0;
    if (x > 0xFFFFFF) x = 0xFFFFFF;
    if (y > 255) y = 255;
    Spr *p = (Spr *)spr_base();
    p->value = (y << 24) | x;
    return p;
}
