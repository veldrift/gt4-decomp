/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Request { char text[0x94]; int id; char pad98[4]; int number; char pada0[4]; unsigned short a4,a6,a8; char padaa[2]; char desc[0x100]; char pad1ac[12]; int b8,bc; };
struct Obj { char pad[0x5a8]; Request *req; char pad5ac[0xfdc-0x5ac]; int number; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_005A5A30(char *,unsigned,const char *,...);
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern char D_006C0CE0[],D_006C0CE8[],D_006C0CF0[];
extern "C" int func_004FD660(Obj *self,char *name,int id,int flag) {
 int result = func_004F0C88(self);
 if(result) {
  func_005A48D8(self->req,0,0x1d8);
  Request *r = self->req;
  if(flag) func_005A5A30(r->text,0x80,D_006C0CE0,name,self->number);
  else func_005A5A30(r->text,0x80,D_006C0CE8,name);
  r->id=id;
  r->number=self->number;
  r->a4 |=7; r->a6 |=7; r->a8 |=7;
  func_005A6AB0(r->desc,D_006C0CF0,0x100);
  r->b8=0;r->bc=0;
  return func_004F0CD0(self,0x49);
 }
 return result;
}
