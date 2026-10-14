#include "spr.h"
struct Timing { volatile long now; volatile long last; char pad10[4]; unsigned char value; char pad15[0x99-0x15]; unsigned char mode; };
struct Scratch { char pad[0x50]; Timing timing; char pad2[0x2c0-0x50-sizeof(Timing)]; unsigned char output; };
extern "C" void func_004A21F0() throw();
static inline Scratch *getScratch() { return (Scratch *)spr_base(); }
extern "C" int func_004A22C0(int frames) {
 Scratch *scratch=getScratch();
 Timing Scratch::*member = &Scratch::timing;
 Timing *t = &(scratch->*member);
 if(frames==0) return (int)t->now;
 long previous=t->last;
 int result;
 if(frames>0) {
  int target=frames-1;
  while((int)(t->now-previous)<target) func_004A21F0();
  func_004A21F0();
  result=(int)(t->now-previous);
 } else {
  long priorNegative=t->last;
  int target=-frames;
  result=1;
  if((int)(t->now-priorNegative)<target) {
   while((int)(t->now-priorNegative)<target) {
    result=0;
    func_004A21F0();
   }
   result=0;
  }
 }
 t->last=t->now;
 if(t->mode==1) scratch->output=t->value;
 else scratch->output=0;
 return result;
}
