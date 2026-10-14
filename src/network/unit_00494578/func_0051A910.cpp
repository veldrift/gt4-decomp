extern "C" void *func_00515DD8(unsigned int) throw();
extern "C" void func_00516030(int,int,unsigned int) throw();
extern "C" void *func_005A48D8(void *,int,unsigned int);
struct Msg { int a,b,c,d,e; };
struct Obj { char pad[0x168]; void (*callback)(Msg *); int value; };
struct Global { char pad[0x118]; int value; };
extern Global *D_0064B4B4;
extern "C" int func_0051A910(Obj *self,int unused1,int unused2,unsigned short *id) {
 int result=-1;
 if(id) {
  char *entry=(char *)func_00515DD8(*id);
  result=2;
  if(entry) {
   *(int *)(entry+4)=-1;
   if(!self->callback) func_00516030(-1,*id,-2);
   else {
    Msg m;
    func_005A48D8(&m,0,20);
    int a=D_0064B4B4->value;
    int b=*(int *)(entry+4);
    int c=*id;
    int e=self->value;
    m.a=a; m.b=b; m.c=c; m.d=4; m.e=e;
    self->callback(&m);
   }
   result=2;
  }
 }
 return result;
}
