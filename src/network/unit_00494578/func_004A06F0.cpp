#include "spr.h"
struct Scratch { char pad[0x110]; int sema,owner,count; };
extern "C" int func_005ADCC0(int);
extern "C" int func_004A06F0() {
 Scratch *s=(Scratch *)spr_base();
 if (--s->count==0) {
  s->owner=-1;
  return func_005ADCC0(s->sema);
 }
}
