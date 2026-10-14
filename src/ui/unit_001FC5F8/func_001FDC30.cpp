/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0x88]; int x88; char p8c[0x14]; int xa0; char pa4[0xc]; int xb0, xb4; char pb8[0x1c]; int xd4; };
extern "C" void func_001FD6E0(S *) throw();
extern "C" void func_001FD860(S *) throw();
extern "C" void func_001FD968(S *) throw();
extern "C" void func_001FDB00(S *) throw();
extern "C" int func_001FDC30(S *s) {
 if (s->xb4 != 0) {
  if (s->x88 != 0) {
   if (s->xb0 != 0) func_001FD968(s);
   else if (s->xa0 == 1) func_001FD6E0(s);
   else func_001FD860(s);
  } else if (s->xd4 != 0) func_001FDB00(s);
 }
}
