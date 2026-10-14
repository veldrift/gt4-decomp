#include "spr.h"
struct State { char p[7]; unsigned char flag; char q[0x26c-8]; unsigned short x,y; char r[0x288-0x270]; int ox,oy; };
extern "C" void func_004A6538(State *, int, int, int, int, int, int, int, int);
extern "C" void func_004A6498(int x1,int y1,int x2,int y2,int a,int b,int c,int d) {
    State *s = (State *)spr_base();
    x1 *= 16;
    x2 *= 16;
    int shift = s->flag != 0 ? 3 : 4;
    int bx = s->x + (s->ox << 4);
    int by = s->y + (s->oy << 4);
    func_004A6538(s, x1+bx, (y1 << shift)+by, x2+bx, (y2 << shift)+by, a<<4,b<<4,c<<4,d<<4);
}
