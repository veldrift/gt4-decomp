#include "spr.h"
typedef unsigned long long u64;
struct Tex { u64 low:20, fmt:6, mid:30, csa:5, high:3; };
struct Spr {
    char pad[0x1B0];
    Tex value;
    char gap[8];
    union { Tex tex; unsigned char b[8]; };
    char gap2[0x10];
    u64 dirty;
};
extern "C" void func_004A4930(int mode) {
    Spr *p = (Spr *)spr_base();
    switch (mode - 1) {
    case 0: p->value.fmt = p->tex.fmt; p->value.csa = p->tex.csa; break;
    case 1: p->value.fmt = 20; p->value.csa = p->tex.csa; break;
    case 3: p->value.fmt = 19; p->value.csa = p->tex.csa; break;
    case 2: p->value.fmt = 20; p->value.csa = 0; break;
    case 4: p->value.fmt = 19; p->value.csa = 0; break;
    }
    p->dirty |= 0x05000500ULL;
}
