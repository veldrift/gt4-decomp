/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int f0; char pad[0x10]; int f14; char rest[0x2c]; int f44; };
struct Obj { char pad[0x40]; int (*f40)(void *); };
extern Obj *D_0064B4B0;
extern "C" int func_00538BF8(void *, int) throw();
extern "C" int func_00538C68(void *) throw();
extern "C" int func_0053DFD8(Blk **out,int arg1,int arg2) {
 int r=2;
 Blk *p=0;
 int s;
 if(out==0) return r;
 *out=0;
 if(arg1==0) return r;
 r=func_00538BF8(&p,0x50);
 if(r) return r;
 s=func_00538BF8(&p->f44,0x2e7c);
 if(s!=0) {
  func_00538C68(&p);
  return s;
 }
 {
  r=D_0064B4B0->f40((char *)p+4);
  s=r;
  if(s==0) goto success;
  func_00538C68(&p->f44);
 }
 func_00538C68(&p);
 return s;
success:
 p->f14=arg2;
 p->f0=arg1;
 *out=p;
 return r;
}
