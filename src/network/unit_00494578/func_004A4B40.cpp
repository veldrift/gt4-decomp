#include "spr.h"
typedef unsigned long long u64;
struct Tex0 { u64 lo:37; u64 cbp:14; u64 cpsm:4; u64 csm:1; u64 csa:5; u64 cld:3; };
struct Obj { char p0[0x1b0]; Tex0 t1; char p1[8]; Tex0 t2; char p2[0x10]; u64 c; char p3[0x2c5-0x1e0]; signed char mode; };
extern "C" void func_004A4AA8(Obj *) throw();
extern "C" void func_004A4B40(unsigned int addr,int mode) {
    Obj *p=(Obj *)spr_base();
    p->mode=mode;
    if(mode==1) mode=0;
    p->t2.cbp=addr>>6;
    p->t1.cbp=addr>>6;
    p->t2.cpsm=mode;
    p->t1.cpsm=mode;
    p->t2.csm=0;
    p->t1.csm=0;
    p->t2.csa=0;
    p->t1.cld=1;
    p->t2.cld=0;
    func_004A4AA8(p);
    p->c |= 0x04000400;
}
