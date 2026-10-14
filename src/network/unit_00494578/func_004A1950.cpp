#include "spr.h"
struct Packet { unsigned int w0,w4,w8,wc; };
struct Scratch { char pad[0x1f8]; Packet *cur; };
extern "C" void func_0049FE28() throw();
extern "C" void func_004A1950(unsigned char id) {
    func_0049FE28();
    Scratch *s = (Scratch *)spr_base();
    Packet *p = s->cur;
    p->wc = (id << 15) | 0x06000000;
    p->w0 = 0x10000000;
    p->w8 = 0x11000000;
    p->w4 = 0;
    p++;
    s->cur = p;
}
