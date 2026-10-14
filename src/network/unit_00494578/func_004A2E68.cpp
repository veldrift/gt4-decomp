#include "spr.h"
struct Spr { char pad[0x298]; int a, b, c, d; };
extern "C" void func_004A2E98(Spr *);
extern "C" void func_004A2E68(int a, int b, int c, int d) {
    Spr *p = (Spr *)spr_base();
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
    return func_004A2E98(p);
}
