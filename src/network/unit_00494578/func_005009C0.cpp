/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { char data[64]; };
struct Request { char pad[0x15]; char name[0x11]; char pad26[2]; int id,zero; char text[32]; int type; Blob data; };
struct Obj { char pad[0xCC]; Blob data; char pad10C[0x5A8-0x10C]; Request *req; char pad5AC[0x608-0x5AC]; int id; char text[256]; char pad70C[0xAF8-0x70C]; char name[0x11]; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern char D_006C0E88[];
extern "C" int func_005009C0(Obj *self,int id,void *text) {
 int result=func_004F0C88(self);
 if(result) {
  func_005A48D8(self->req,0,0xC4);
  Request *r=self->req;
  func_005A6AB0(r->name,self->name,0x11);
  r->id=id;r->type=2;r->zero=0;
  r->data=self->data;
  if(text) func_005A6AB0(r->text,text,0x20); else r->text[0]=0;
  self->id=id;
  func_005A6AB0(self->text,D_006C0E88,0x100);
  return func_004F0CD0(self,0x15);
 }
 return result;
}
