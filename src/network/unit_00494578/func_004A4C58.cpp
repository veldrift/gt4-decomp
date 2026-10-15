#include "spr.h"
typedef unsigned long u64;
struct Bits {
    u64 lo : 56;
    u64 f : 5;
    u64 hi : 3;
};
struct Spr {
    char pad[0x1C0];
    Bits unk1C0;
    char pad2[0x10];
    u64 unk1D8;
};
extern "C" void func_004A4C58(unsigned a0) {
    Spr *p = (Spr *)spr_base();
    p->unk1C0.f = a0;
    p->unk1D8 |= 0x4000400;
}
