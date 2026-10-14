/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned int u32;
typedef unsigned long u64;
struct Arg { u32 a,b; u64 c; };
struct Spr { char pad[0x1D8]; u64 f1D8; char p1E0[0x18]; u32 *p1F8; char *p1FC; char p200[8]; u32 *p208; };
extern "C" void func_0049FE28() throw();
extern "C" void func_004A1EB8(Arg *arg) {
 Spr *s=(Spr *)spr_base();
 func_0049FE28();
 u32 *p=s->p1F8;
 p[0]=0x50000000;
 p[1]=arg->a & 0x0FFFFFFF;
 p[2]=0x11000000;
 p[3]=0;
 p+=4;
 s->p1F8=p;
 char *end=s->p1FC;
 u32 *q=(u32 *)(end-0x20);
 s->p1FC=(char *)q;
 *s->p208=(u32)q & 0x0FFFFFFF;
 q[0]=0x50000000;
 q[1]=arg->b & 0x0FFFFFFF;
 q[4]=0x20000000;
 s->p208=(u32 *)(end-0xC);
 s->f1D8=arg->c;
}
