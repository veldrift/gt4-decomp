/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Spr { char pad[0x2B0]; float x,y,w,h; };
extern "C" int func_004A2BC8(Spr *);
static inline float add(float a, float b) { return a+b; }
extern "C" int func_004A2B58(float x,float y,float w,float h) {
    float one=1.0f, zero=0.0f;
    Spr *s=(Spr *)spr_base();
    w = add(x,w);
    h = add(y,h);
    __asm__("max.s %0, %0, %1" : "+f"(h) : "f"(zero));
    __asm__("max.s %0, %0, %1" : "+f"(w) : "f"(zero));
    __asm__("min.s %0, %0, %1" : "+f"(h) : "f"(one));
    __asm__("max.s %0, %0, %1" : "+f"(y) : "f"(zero));
    __asm__("max.s %0, %0, %1" : "+f"(x) : "f"(zero));
    __asm__("min.s %0, %0, %1" : "+f"(w) : "f"(one));
    __asm__("min.s %0, %0, %1" : "+f"(y) : "f"(one));
    __asm__("min.s %0, %0, %1" : "+f"(x) : "f"(one));
    w-=x;
    h-=y;
    s->x=x; s->y=y; s->w=w; s->h=h;
    return func_004A2BC8(s);
}
