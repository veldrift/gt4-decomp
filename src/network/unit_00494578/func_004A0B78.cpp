#include "spr.h"
struct Packet { char pad[0x88]; short y; short x; char pad2[4]; short w; short h; };
struct Scratch { char pad[0x50]; Packet packet; };
extern "C" int func_004A0970(Packet *) throw();
extern "C" int func_004A0B78(int x, int y, int w, int h) {
    Packet Scratch::*member = &Scratch::packet;
    Scratch *base = (Scratch *)spr_base();
    Packet *p = &(base->*member);
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    return func_004A0970(p);
}
