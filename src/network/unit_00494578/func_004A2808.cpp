#include "spr.h"
struct Spr { char pad0[0x198]; signed char a; char pad1[3]; signed char b; char pad2[0x3B]; unsigned long flags; };
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void setBits(Spr *p, unsigned long m) { p->flags |= m; }
extern "C" void func_004A2808(signed char a, float x) {
    Spr *p = (Spr *)spr_base();
    unsigned long m = 0x200020;
    x *= 128.0f;
    x = maxf(x, 0.0f);
    x = minf(x, 255.0f);
    int b = (int)x;
    p->a = a;
    setBits(p, m);
    p->b = b;
}
