/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[12]; int data; char rest[0x48-16]; };
struct List { char data[12]; };
struct Obj { char pad[0x30]; List lists[3]; Entry entries[32]; char pad954[4]; int handle; };
struct Config { int a,b,c,d,e,f,g,h,i; void (*cb1)();void (*cb2)();void (*cb3)();Obj *obj; };
extern "C" void func_00503850(void *) throw();
extern "C" int func_00528BA8(void *,Config *);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_0057CA70(void *);
extern "C" void func_0057CB00(void *,void *);
extern "C" void func_005A48D8(void *,int,unsigned);
extern "C" void func_00504180();
extern "C" void func_00503FD0();
extern "C" void func_00503F48();
struct Guard { Obj *obj; Guard(Obj *p):obj(p) { func_00576788(p); } ~Guard() { func_005767C0(obj); } };
extern "C" void func_00503B30(Obj *self) {
 Entry *cur=self->entries;
 List *list=&self->lists[0];
 Guard guard(self);
 Config config;
 func_005A48D8(&config,0,0x34);
 config.a=5000;config.b=32;config.c=0x400;config.d=0x2000;config.e=0x2000;config.f=5;
 config.cb1=func_00504180;config.cb2=func_00503FD0;config.cb3=func_00503F48;
 config.g=0;config.obj=self;
 func_00528BA8(&self->handle,&config);
 func_0057CA70(list);func_0057CA70(&self->lists[1]);func_0057CA70(&self->lists[2]);
 for(int i=0;i<32;i++,cur++) {
  int handle=self->handle;
  func_00503850(cur);
  cur->data=handle;
  func_0057CB00(list,cur);
 }
}
