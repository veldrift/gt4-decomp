/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int a,b,status; };
struct S { char p0[0xf8]; int f8; char pfc[0x10c]; int f208; char p20c[12]; State state; };
extern "C" long func_00578560();
extern "C" void func_00578B10(int);
static inline int difference(int expected, int actual) { return expected - actual; }
extern "C" int func_00501A78(S *self) {
 if (self->f208 == 0) return 0;
 if (self->f8 != 0) return 0;
 State *p = &self->state;
 long start = func_00578560();
 while (difference(8, p->status) == 0) {
  if (func_00578560() - start > 0x4c4b3f) return 0;
  func_00578B10(5000);
 }
 return 1;
}
