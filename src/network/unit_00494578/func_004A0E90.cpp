#include "spr.h"
extern "C" int func_005AE850(void *) throw();
extern "C" int func_005AD9D0(int, int);
extern "C" int func_005ADCB0(int);
struct Spr { char pad[0x74]; int a; char p78[8]; int b; char p84[8]; int c; char p90[0x64]; int d,e,f; };
extern "C" int func_004A0E90() {
    Spr *p = (Spr *)spr_base();
    func_005AE850((void *)0);
    func_005AE850((void *)1);
    func_005AE850((void *)2);
    func_005AD9D0(0,p->d);
    func_005AD9D0(1,p->e);
    func_005AD9D0(2,p->f);
    func_005ADCB0(p->a);
    func_005ADCB0(p->b);
    return func_005ADCB0(p->c);
}
