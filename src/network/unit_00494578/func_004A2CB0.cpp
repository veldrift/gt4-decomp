/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
struct Scratch {
    char pad0[7]; unsigned char half;
    char pad8[0x280]; int x, y;
};
extern "C" void func_004A2D20(int, int, int, int) throw();
extern "C" void func_004A2CB0(float x, float y, float w, float h) {
    Scratch *p = (Scratch *)spr_base();
    if (p->half) {
        y *= 0.5f;
        h *= 0.5f;
    }
    int iw = (int)w;
    x += (float)p->x;
    y += (float)p->y;
    return func_004A2D20((int)x, (int)y, iw, (int)h);
}
