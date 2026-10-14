#include "spr.h"
struct Packet { unsigned int a,b,c,d; };
struct Scratch { char pad[0x1f8]; unsigned int cur; };
extern "C" char *func_004ABC90(unsigned int n) {
    Scratch *s=(Scratch*)spr_base();
    Packet *p=(Packet*)s->cur;
    unsigned int bytes;
    if(n) {
        p->b=0;
        p->a=n|0x10000000;
        p->d=n|0x51000000;
        p->c=0;
        bytes = n;
        bytes <<= 4;
        s->cur += bytes;
        s->cur += 16;
    }
    return (char*)p+16;
}
