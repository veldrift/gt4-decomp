#include "spr.h"
/* NOT judged with `try`: the base is one opaque `li` (see the o1 report). */
struct Sub {
    char pad[0x8C];
    short unk8C;
    short unk8E;
};
struct Spr {
    char pad[0x50];
    Sub unk50;
};
extern "C" void func_004A0970(void *) throw();
extern "C" void func_004A0BE0(short a0, short a1) {
    Spr *s = (Spr *)spr_base();
    Sub *p = &s->unk50;
    p->unk8C = a0;
    p->unk8E = a1;
    return func_004A0970(p);
}
