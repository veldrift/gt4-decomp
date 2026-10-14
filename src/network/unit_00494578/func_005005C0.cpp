/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0x5ac]; int handle[4]; int flag; char name[0x20]; int flag2; char q[0x2228-0x5e4]; int value; char name2[0xc]; };
struct Request { int f0,f4; Obj *f8; char p[8]; void (*cb14)(); Obj *f18; void (*cb1c)(); Obj *f20; int timeout; char rest[0x98-0x28]; };
extern "C" void func_004FAC58();
extern "C" void func_004FACC8();
extern "C" void func_004F8820(Obj*,int) throw();
extern "C" int func_0052EF10(Request*,int*);
extern "C" int func_0052F7B0(int*);
extern "C" int func_00534170(void*);
extern "C" void *func_005A48D8(void*,int,unsigned int);
extern "C" char *func_005A609C(char*,const char*);
extern "C" void func_005A6AB0(void*,const void*,int) throw();
extern "C" int func_005005C0(Obj *o,const char *name) {
 Request req;
 int out[3];
 func_005A48D8(&req,0,0x98);
 func_005A48D8(out,0,0xc);
 func_0052F7B0(o->handle);
 int status=func_00534170(&req);
 func_004F8820(o,status);
 if(status!=0) return 0;
 {
  req.f4=0; req.f8=o;
  req.cb14=func_004FAC58;
  req.cb1c=func_004FACC8;
  req.f18=o; req.f20=o;
  req.timeout=10;
  if(func_0052EF10(&req,out)!=0) return 0;
  o->value=out[2];
  func_005A6AB0(o->name2,name,0xc);
  o->flag=1;
  func_005A609C(o->name,name);
  o->flag2=1;
  return 1;
 }
}
