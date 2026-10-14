#include "spr.h"
struct Scratch { char pad[0x230]; float value; };
static inline float max_s(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float min_s(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void func_004A3088(float x) {
    Scratch *p = (Scratch *)spr_base();
    float one = 1.0f;
    float zero = 0.0f;
    x = one - x;
    x = max_s(x, zero);
    x = min_s(x, one);
    p->value = x;
}
