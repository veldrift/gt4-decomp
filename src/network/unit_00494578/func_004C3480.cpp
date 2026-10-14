/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { int pad; unsigned char *data; unsigned char *items; char gap[8]; unsigned char *base; };
extern "C" int func_004C4CB8(unsigned short);
extern "C" int func_004C3480(S *s, unsigned short *key, unsigned char **a, unsigned char **b, unsigned char **c) {
 int x = func_004C4CB8(key[0]);
 if(x <= 0) return 0x8000112f;
 {
  int y = func_004C4CB8(key[1]);
  if(y < 0) return 0x8000112f;
  {
   int offset = (x * 85 + y) * 5 - 425;
   unsigned char *p = s->data + offset;
   int v = (p[4] & 15) << 16;
   v |= p[2] << 8;
   v |= p[3];
   if (v == 0xfffff) *c = 0;
   else *c = s->base + v;

   *a = s->items + (((p[4] & 240) << 12) | (p[0] << 8) | p[1]) * 6;
   *b = s->items + (((p[9] & 240) << 12) | (p[5] << 8) | p[6]) * 6;
  }
 }
 return 0;
}
