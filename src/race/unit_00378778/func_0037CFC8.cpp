/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x2c0]; signed char a,b; unsigned char c; signed char d; };
extern char D_00621250[],D_00621258[],D_00621260[],D_00621268[];
extern "C" void *func_0037CDD8(int,int) throw() __attribute__((const));
extern "C" void func_0037CF58(Obj *,void *) throw();
extern "C" void func_0037CFC8(Obj *p) {
 int b=p->b;
 int d=p->d;
 if(b!=0) {
  if(b>0) return func_0037CF58(p,D_00621250);
  return func_0037CF58(p,D_00621258);
 }
 if(d!=0) {
  if(d>0) return func_0037CF58(p,D_00621260);
  return func_0037CF58(p,D_00621268);
 }
 func_0037CF58(p,func_0037CDD8(p->a,p->c));
}
