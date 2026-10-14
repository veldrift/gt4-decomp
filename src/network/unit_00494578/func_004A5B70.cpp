#include "spr.h"
struct Scratch { char pad[0x1fc]; int value; };
extern "C" int func_004A5B70(int amount) {
    Scratch *p = (Scratch *)spr_base();
    int old = p->value;
    int v = old - (amount << 4);
    p->value = v;
    return v;
}
