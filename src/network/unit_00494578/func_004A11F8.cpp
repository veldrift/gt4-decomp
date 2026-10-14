#include "spr.h"
struct Pair { int a,b; };
struct Block { char pad[0x15]; unsigned char a,b,c,d; };
struct State { char pad[0x50]; Block block; char p[0x20c-0x50-sizeof(Block)]; Pair *current; };
extern "C" void func_004A0F08(int) throw();
extern "C" void func_004A0F68(int) throw();
extern "C" void func_004A0F38(int) throw();
extern "C" void func_004ABA50(int,int);
extern "C" void func_004A11F8(Pair *p) {
 State *s=(State *)spr_base();
 volatile Block *b=&s->block;
 if (!p) { p=s->current; if (!p) return; }
 func_004A0F08(1);
 func_004A0F08(2);
 func_004A0F68(1);
 func_004A0F68(2);
 b->b=0; b->c=0; b->d=0; b->a=0;
 if(p->a) func_004ABA50(1,p->a);
 if(p->b) func_004ABA50(2,p->b);
 func_004A0F38(1);
 return func_004A0F38(2);
}
