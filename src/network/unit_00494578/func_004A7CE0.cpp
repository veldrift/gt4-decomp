#include "spr.h"
struct Spr { char pad0[7]; unsigned char flag; char pad1[0x288-8]; int x,y,w,h; };
extern "C" void func_004A7CE0(int *x, int *y, int *w, int *h) {
    Spr *s = (Spr *)spr_base();
    *x = s->x;
    *y = s->y;
    *w = s->w;
    *h = s->h;
    if (s->flag) {
        *y *= 2;
        *h *= 2;
    }
}
