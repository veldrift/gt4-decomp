/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned int D_006B9B98[];
static inline int test(unsigned int *p, int i) {
 return ((long)p[i / 32] >> (i % 32)) & 1;
}
extern "C" int func_004C9580(unsigned int *p, int i) {
 if (!p) return 1;
 if (i >= 400) {
  unsigned int packed = D_006B9B98[i];
  int n = 3;
  int v;
  while ((v = packed & 255) != 0) {
   if (test(p,v)) return 1;
   packed >>= 8;
   if (n-- <= 0) break;
  }
  return 0;
 }
 return test(p,i);
}
