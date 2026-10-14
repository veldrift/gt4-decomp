#include "spr.h"
typedef long s64;
struct State { char pad0[0x99]; unsigned char a,b,c; };
struct Spr { char pad0[0x50]; State state; char padEC[4]; s64 mask; };
extern "C" void func_004A0890(int,int,int);
extern "C" void func_004A0970(State *);
extern "C" void func_004A08E0();
static inline void update(Spr *p, int a, int b, int c) {
    State *s = &p->state;
    if (s->a != a || s->b != b || s->c != c) {
        func_004A0890(a,b,c);
        func_004A0970(s);
        func_004A08E0();
        *(s64 *)((char *)p + 0xD0) = -0x201;
        *(s64 *)0x12001010 = -0x201;
    }
}

extern "C" void func_004A0808(int a, int b, int c) {
    update((Spr *)spr_base(), a, b, c);
}
