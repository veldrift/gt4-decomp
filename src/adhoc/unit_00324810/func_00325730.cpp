/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00841B80;
extern "C" void func_00323D08(void *);
extern "C" int func_00325860(void *);
extern "C" void func_00574D78(void *);
struct E { int a,b,c; };
extern "C" int func_00325730(void *arg0) {
 E *p = (E *)((char *)arg0 + 0x30);
 int n = 0x7ff;
 func_00574D78(arg0);
 do {
  p->a = 0;
  void *h = &p->c;
  --n;
  p->b = D_00841B80;
  ++p;
  func_00323D08(h);
 } while (n != -1);
 return func_00325860(arg0);
}
