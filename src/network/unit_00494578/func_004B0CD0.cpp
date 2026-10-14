/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int v[6]; };
struct Result { int status, exists, a, b; char pad[0x30]; };
struct Src { char pad[0x48]; int handle; };
extern "C" void func_004AF6B8(void *);
extern "C" const char *func_004AC798(int);
extern "C" void func_004AC7B8(int);
extern "C" void func_00550EE8(Result *, const char *);
extern "C" Blob *func_004B0CD0(Blob *out, void *, Src *src) {
 Blob b;
 int h = src->handle;
 func_004AF6B8(&b);
 Result r;
 func_00550EE8(&r, func_004AC798(h));
 b.v[0] = 9;
 if (r.status == 0) {
  b.v[0] = 0;
  b.v[1] = r.exists != 0;
  b.v[2] = r.b;
  b.v[3] = r.a;
  b.v[5] = 0;
 }
 func_004AC7B8(h);
 *out = b;
 return out;
}
