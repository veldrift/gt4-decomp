#include "spr.h"
struct Obj { char pad[0x94]; short x,y; };
struct Spr { char pad[0x50]; Obj obj; };
extern "C" int func_004A0970(Obj *) throw();
extern "C" int func_004A0BB0(int x,int y) {
    Spr *p = (Spr *)spr_base();
    Obj *o = &p->obj;
    o->x=x;
    o->y=y;
    return func_004A0970(o);
}
