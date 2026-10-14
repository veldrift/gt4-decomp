#include "spr.h"
/* NOT judged with `try`: the base is one opaque `li` (see the o1 report). */
struct R {
    char pad0[0x188];
    unsigned long l188;
    char pad1[0x1D8 - 0x190];
    unsigned long l1D8;
    char pad2[0x23C - 0x1E0];
    float f23C;
    char pad3[0x248 - 0x240];
    unsigned int w248;
};
extern "C" void func_004A2590(R *) throw();

extern "C" void func_004A25F0(unsigned int a0, unsigned int a1) {
    R *r = (R *)spr_base();
    switch (a1) {
    case 0x30:
        r->f23C = 0x1.FFFBFEp+31f;
        break;
    case 0x31:
        r->f23C = 0x1.FFF7FEp+23f;
        break;
    case 0x32:
    case 0x3A:
        r->f23C = 65531.0f;
        break;
    }
    unsigned long s1 = (unsigned long)(a1 & 0xF) << 24;
    unsigned int a3 = (unsigned int)(int)r->f23C | 0xFF000000;
    unsigned long a2 = r->l1D8 | 0x80008;
    r->w248 = a3;
    r->l188 = (((r->l188 & ~0x1FFUL) | ((a0 >> 11) & 0x1FF)) & (unsigned long)(int)0xF0FFFFFF) | s1;
    r->l1D8 = a2;
    return func_004A2590(r);
}
