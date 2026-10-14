#include "spr.h"
struct Scratch { char pad[0x2c8]; int value; };
struct Value { int x; };
extern "C" void func_004ABB00(Scratch *);
extern "C" void func_004A19B0(Value value) {
 Scratch *s=(Scratch *)spr_base();
 s->value=value.x;
 return func_004ABB00((Scratch *)s);
}
