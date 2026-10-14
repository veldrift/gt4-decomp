#include "spr.h"
/* NOT judged with `try`: the base is one opaque `li` (see the o1 report). */
typedef unsigned long u64;
struct Bits {
    u64 lo : 35;
    u64 f : 2;
    u64 hi : 27;
};
struct Spr {
    char pad[0x1C0];
    Bits unk1C0;
    char pad2[0x10];
    u64 unk1D8;
};
extern "C" void func_004A4500(unsigned a0) {
    Spr *p = (Spr *)spr_base();
    p->unk1C0.f = a0;
    p->unk1D8 |= 0x4000400;
}
