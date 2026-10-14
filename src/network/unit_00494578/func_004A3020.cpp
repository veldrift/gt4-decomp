#include "spr.h"
struct Scratch { char pad[0x240]; float value; };
extern "C" void func_004A2590(unsigned long) throw();
extern "C" void func_004A3020(float value) {
 Scratch *s=(Scratch *)spr_base();
 s->value=value;
 return func_004A2590((unsigned long)s);
}
