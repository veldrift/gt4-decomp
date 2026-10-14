#include "spr.h"
struct State { unsigned char pad[0x99]; unsigned char a, b, c; };
extern "C" int func_0057FD08(short, short, short, short);
extern "C" int func_004A08E0(void) {
    State *p = (State *)((char *)spr_base() + 0x50);
    return func_0057FD08(5, p->a, p->b, p->c);
}
