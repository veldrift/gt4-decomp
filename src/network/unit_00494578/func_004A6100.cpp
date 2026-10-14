#include "spr.h"
struct Scratch { char pad[0xb00]; float r,g,b,a; };
extern "C" void func_004A6100(float r, float g, float b, float a) {
    Scratch *p = (Scratch *)spr_base();
    p->r = r * 255.0f;
    p->g = g * 255.0f;
    p->b = b * 255.0f;
    p->a = 128.0f * a;
}
