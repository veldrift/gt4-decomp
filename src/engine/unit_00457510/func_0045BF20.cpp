/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem { char pad[0x3F4]; int flag; float f3F8; float f3FC; char pad2[0x4F0 - 0x400]; };
struct Obj { char pad[0xC]; Elem el[4]; };
struct Cfg { char pad[0x54C]; float f54C; };
extern "C" Cfg *func_0045B8A8(Obj *, int) throw();
extern "C" void func_0045C488(Elem *, float);
extern "C" void func_0045C530(Elem *, int);
extern "C" void func_0045C578(Elem *);
extern "C" void func_0045C5A8(Elem *);
extern "C" void func_0045C648(Elem *);
extern "C" void func_0045C668(Elem *, float);
extern "C" void func_0045C9F8(Elem *);
extern "C" void func_0045CA60(Elem *, float);
extern "C" void func_0045CC60(Elem *, Cfg *);
extern "C" int func_0045D8E0(Elem *);
extern "C" void func_0045DB78(Elem *, float);
extern "C" void func_0045DF80(Elem *);
extern "C" void func_0045E028(Elem *);
extern "C" void func_0045E570(Elem *);
extern "C" void func_0045BF20(Obj *o, int i) {
 float f=1.0f;
 func_0045C488(&o->el[i],func_0045B8A8(o,i)->f54C);
 func_0045C530(&o->el[i],0);
 for(int n=0;n<2;n++) {
  func_0045C578(&o->el[i]);
  func_0045C5A8(&o->el[i]);
  func_0045C648(&o->el[i]);
  if(func_0045D8E0(&o->el[i])==0) {
   func_0045DB78(&o->el[i],2.0f); break;
  }
  f=o->el[i].f3FC;
  func_0045DB78(&o->el[i],f);
  func_0045C668(&o->el[i],f);
  if(o->el[i].flag) func_0045E028(&o->el[i]);
  else func_0045E570(&o->el[i]);
 }
 func_0045CA60(&o->el[i],f);
 func_0045DF80(&o->el[i]);
 func_0045C9F8(&o->el[i]);
 func_0045CC60(&o->el[i],func_0045B8A8(o,i));
}
