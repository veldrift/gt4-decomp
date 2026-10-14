#include "spr.h"
struct Mode { unsigned long mode:2, rest:62; };
struct Dirty { unsigned long pad:38, dirty:1, rest:25; };
struct Scratch { char pad0[0x150]; Mode mode; char pad158[0x80]; Dirty dirty; char pad1e0[0xE0]; unsigned char saved; };
extern "C" void func_004A5FE0(unsigned int kind) {
 Scratch *p=(Scratch *)spr_base();
 switch(kind) {
 case 0: p->mode.mode=0; break;
 case 3: p->mode.mode=2; break;
 case 4: p->mode.mode=3; break;
 case 1: p->mode.mode=p->saved|2; break;
 case 2: p->mode.mode=p->saved^3; break;
 }
 p->dirty.dirty=1;
}
