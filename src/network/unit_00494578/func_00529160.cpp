/* compiler: ee-gcc2.96-as2004 */
struct Obj { int a; int pad4; void *inner; char padc[0x58]; int value64; char pad68[12]; int state; char pad78[8]; int value80; char pad84[16]; int value94,value98; };
struct Input { long value __attribute__((packed, aligned(4))); int a,b,c; };
extern "C" int func_0053DFD8(void **,int,int);
extern "C" int func_0053F268(void *,int);
extern "C" int func_0053EEA8(void *,long,int,void (*)(void),Obj *);
extern "C" void func_0052D0E8(void);
extern "C" int func_00529160(Obj *p,Input *in) {
 if(!p) return 0xd2f2;
 int b=in->b;
 if(!b) return 2;
 if(p->state) return 0xd2f4;
 int c=in->c;
 p->value94=b;
 p->value98=c;
 if(!p->inner) {
  void **inner=&p->inner;
  int r=func_0053DFD8(inner,p->a,p->value80);
  if(r) return r;
  r=func_0053F268(*inner,p->value64);
  if(r) return r;
 }
 int r=func_0053EEA8(p->inner,in->value,in->a,func_0052D0E8,p);
 if(!r) p->state=1;
 return r;
}
