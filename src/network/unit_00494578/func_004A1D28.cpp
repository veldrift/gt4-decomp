#include "spr.h"
typedef unsigned int u32;
struct Packet { u32 w[4]; };
struct State {
    char p0[3]; unsigned char b3; char p4[0x3C]; u32 color;
    char p44[0x19C]; union { unsigned long flags; u32 flagWords[2]; };
    char p1e8[0x10]; u32 cur;
    char p1fc[0xC]; u32 prev, last, out;
    char p214[0xAE]; unsigned char b2c2, b2c3;
};
extern "C" void func_0049FE28() throw();
extern "C" void func_004A1E08();
inline bool active(State *s) { return s->b2c3 != 0; }
extern "C" char *func_004A1D28() {
    State *s = (State *)spr_base();
    if (s->b2c3) func_004A1E08();
    func_0049FE28();
    char *p = (char *)s->cur;
    if (s->b2c2) {
        ((Packet *)p)->w[0] = 0x20000000;
        ((Packet *)p)->w[2] = 0;
        ((Packet *)p)->w[3] = 0;
        char *link = p + 4;
        p += 16;
        ((Packet *)s->last)->w[2] = (u32)link;
        ((Packet *)s->last)->w[3] = s->prev;
    }
    s->out = (u32)p;
    char *start = p;
    p += 16;
    ((Packet *)start)->w[1] = (u32)p;
    s->prev = (u32)(p + 4);
    ((Packet *)p)->w[0] = 0x20000000;
    p += 16;
    ((Packet *)start)->w[0] = (u32)p;
    ((Packet *)p)->w[0] = 0x10000000;
    ((Packet *)p)->w[1] = 0;
    ((Packet *)p)->w[2] = 0x20000000;
    ((Packet *)p)->w[3] = 0xC0C0C0C0;
    p += 16;
    s->b2c3 = 1;
    s->b3 = 0;
    s->cur = (u32)p;
    s->color = 0xC0C0C0C0;
    s->flags = 0;
    return start;
}
