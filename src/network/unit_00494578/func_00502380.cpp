/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p0[0x98]; int f98; char p9c[0x16c]; int f208,f20c,f210; void *f214; };
extern char D_00502490[];
extern "C" void func_00574E78(void *);
extern "C" void *func_00578610(int);
extern "C" int func_005788B8(void *);
extern "C" void *func_00578968(void *, void *, void *);
extern "C" int func_00578B50(unsigned int, int);
extern "C" void func_00502380(S *self) {
 int data[8];
 int stack[4];
 if (self->f208 != 0 && self->f214 == 0) {
  self->f20c = 0;
  func_00574E78((char *)self + 0x38);
  self->f98 = 0;
  data[0] = (int)D_00502490;
  data[1] = (int)self;
  int *p = stack;
  p[0] = 0;
  p[1] = 0x4000;
  void *thread = func_00578968(data, p, func_00578610(func_00578B50(3, 0)));
  func_005788B8(thread);
  self->f214 = thread;
 }
}
