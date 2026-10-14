#include "spr.h"
struct V { float f[4]; };
struct S { char pad[0xBA0]; V a,b,c; };
extern "C" void func_0049F3C0(unsigned int k,float f) {
    S *s=(S *)spr_base();
    switch(k) {
    case 0: s->a.f[0]=f; s->a.f[1]=f; s->a.f[2]=f; s->a.f[3]=1.0f; return;
    case 2: s->b.f[0]=f; s->b.f[1]=f; s->b.f[2]=f; s->b.f[3]=1.0f; return;
    case 3: s->c.f[0]=f; s->c.f[1]=f; s->c.f[2]=f; s->c.f[3]=0.0f; return;
    }
}
