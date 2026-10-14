#include "spr.h"
struct Regs { char pad[0x228]; int color; };
extern "C" int func_004AA0D0(void *, void *, float, float, float, float, float);
void func_004A3040(void *a, void *b, float r, float g, float bl, float al) {
    Regs *p = (Regs *)spr_base();
    p->color = func_004AA0D0(a, b, r, g, bl, al, 255.0f);
}
