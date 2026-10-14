#include "spr.h"
struct Port { char p0[0x60]; long mode; char p68[0x31]; char a,b,c; };
struct Scratch { char p0[0x50]; Port port; };
extern "C" void func_004A0890(int a, int b, int c) {
 Scratch *scratch = (Scratch *)spr_base();
 Port *p = &scratch->port;
 p->b = b;
 p->a = a;
 p->c = c;
 if (a == 1) {
  if (c == a) { p->mode = 3; return; }
  p->mode = 1;
  return;
 }
 p->mode = 2;
}
