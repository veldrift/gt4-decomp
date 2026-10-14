/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { int state; char pad[0x418]; };
struct Obj { char pad[0x20]; Item items[2]; char pad858[0]; int current; int x85c; int done; };
extern "C" int func_004B4B40(Obj *,int) throw();
extern "C" void func_004B5628(Obj *) throw();
extern "C" void func_004B61A8(Obj *) throw();
extern "C" int func_004B6FA0(Obj *p) {
 if (p->done) return 1;
 Item *i=&p->items[1-p->current];
 switch(i->state) {
 case 0: return 0;
 case 1:
 if (func_004B4B40(p,1)<=0) return 0;
 func_004B5628(p); func_004B61A8(p); return 1;
 case 2:
 func_004B5628(p); func_004B61A8(p); i->state=1; return 1;
 default: return 0;
 }
}
