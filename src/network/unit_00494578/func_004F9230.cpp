/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Entry { char text[32]; int state, limit, total; };
struct Obj { char pad0[0xcb8]; int cb8; char padcbc[0x320]; int fdc; char text[32]; char pad1000[0x20]; Entry records[100]; char pad2150[0xd8]; int handle; };
struct Msg { int type, spare, state; char text[32]; };
extern "C" void func_004F8820(void *, int) throw();
extern "C" int func_0052EAF8(signed char, int, int, int, int, int, void *);
extern "C" int func_0052F6F0(int *, int);
extern "C" int func_005A6AB0(void *, void *, int) throw();
extern "C" int func_004F9230(Obj *self) {
 Msg msg;
 int result;
 if (self->handle == 0) return 0;
 for (int i=0; i<100; i++) {
  self->records[i].text[0]=0;
  self->records[i].state=0;
  self->records[i].limit=0x7fffffff;
  self->records[i].total=0x7fffffff;
 }
 msg.type=1;
 msg.state=self->fdc;
 func_005A6AB0(msg.text,self->text,32);
 int status=func_0052EAF8(0x40,self->handle,-1,2,self->cb8,44,&msg);
 if (status != 0) { func_004F8820(self,status); return 0; }
 result=-999;
 status=func_0052F6F0(&result,self->handle);
 if (status != 0) { func_004F8820(self,status); return 0; }
 self->records[result].state=self->fdc;
 func_005A6AB0(self->records[result].text,self->text,32);
 return 1;
}
