/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0x84]; int x84, x88; char p8c[0x28]; int xb4; };
extern "C" int func_0054EBE0(int);
extern "C" int func_001FE200(S *s) {
 int h = s->xb4;
 if (h == 0) return 0;
 {
  int r = func_0054EBE0(h);
  s->x88 = 0;
  s->x84 = 0;
  return r;
 }
}
