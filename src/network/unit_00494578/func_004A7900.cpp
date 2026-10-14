#include "spr.h"
struct Spr { unsigned char dirty; char pad[0xBCF]; float x, y, z, w, ix, iy, iz, iw; };
extern "C" float func_004A78C8(float) throw() __attribute__((const));
static inline Spr *scratch() { return (Spr *)spr_base(); }
extern "C" void func_004A7900(float x, float y, float z) {
    float w = 1.0f;
    scratch()->x = x;
    scratch()->y = y;
    scratch()->z = z;
    scratch()->w = w;
    scratch()->ix = func_004A78C8(x);
    scratch()->iy = func_004A78C8(y);
    scratch()->iz = func_004A78C8(z);
    scratch()->iw = w;
    scratch()->dirty = 1;
}
