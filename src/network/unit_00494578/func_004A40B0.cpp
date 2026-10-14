#include "spr.h"
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct Spr {
    char pad0[0x2d8];
    float u, v;
    char pad1[0xfac-0x2e0];
    float inverse;
    char pad2[0xfbc-0xfb0];
    float alpha;
    char pad3[0xfcc-0xfc0];
    float positive;
};
extern "C" void func_004A40B0(float u, float v) {
    float a = minf(maxf(v * 255.0f, 0.0f), 255.0f);
    Spr *p = (Spr *)spr_base();
    p->positive = maxf(u, 0.0f);
    p->u = u;
    p->v = v;
    p->inverse = 255.0f - a;
    p->alpha = a + 0.1f;
}
