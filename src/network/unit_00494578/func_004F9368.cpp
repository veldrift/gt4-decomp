/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p0[0xcb8]; int cb8; char pcc[0x156c]; int handle; };
extern "C" void func_004F8820(void *, int) throw();
extern "C" void func_004F9018(void *, void *, int) throw();
extern "C" int func_0052EAF8(signed char, int, int, int, int, int, void *);
extern "C" int func_0052F6F0(int *, int);
extern "C" int func_004F9368(S *self, int arg1) {
 int data[4];
 int result;
 if (self->handle == 0) return 0;
 data[0] = 4;
 data[2] = arg1;
 int status = func_0052EAF8(0x40, self->handle, -1, 2, self->cb8, 12, data);
 if (status != 0) {
  func_004F8820(self, status);
  return 0;
 }
 result = -999;
 status = func_0052F6F0(&result, self->handle);
 if (status != 0) {
  func_004F8820(self, status);
  return 0;
 }
 func_004F9018(self, data, result);
 return 1;
}
