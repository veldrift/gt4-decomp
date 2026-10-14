/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Spr { char pad[0x1f8]; unsigned int *cursor; char pad1[0x102c-0x1fc]; int count; };
extern unsigned int D_00624C64, D_00624C68;
extern unsigned int D_00624C6C;
static inline void write_tail(Spr *spr, unsigned int addr) {
 unsigned int *count = &D_00624C6C;
 if (*count != 0) {
  unsigned int *p = spr->cursor;
  p[0] = 0x30000006;
  p[1] = D_00624C64;
  p[2] = 0x11000000;
  p[3] = 0x51000006;
  p[4] = *count | 0x30000000;
  p[5] = addr & 0x0fffffff;
  p[6] = 0;
  unsigned int end = 0x50000002;
  p[7] = *count | 0x51000000;
  p[8] = 0x30000002;
  p[9] = D_00624C68;
  p[10] = 0x11000000;
  p[11] = end;
  spr->cursor = p + 12;
  int total = spr->count;
  total += *count;
  (void)(spr->count = total);
 }
}

extern "C" void func_00499C38(unsigned int addr) { write_tail((Spr *)spr_base(), addr); }
