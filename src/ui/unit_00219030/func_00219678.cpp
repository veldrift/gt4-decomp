/* compiler: ee-gcc2.96-stl */
#include <stl_tree.h>
struct Obj { int x; char *vt; };
struct Value { int first; Obj *second; };
typedef _Rb_tree_iterator<Value,Value &,Value *> Iter;
struct Self { char pad[0x20]; Obj *p20; Obj *p24; };
struct VE { short d,i; void (*fn)(void *, ...); };
struct Widget;
struct Object;
struct Scope;
struct Module;
struct Update;
extern "C" Iter func_003065B0(Obj *);
extern "C" Iter func_003065C8(Obj *);
extern "C" void func_00229540(void *);
extern "C" void *func_0030BB18(void *);
extern "C" void func_00309378(void *,int);
extern "C" int func_00213158(Self *) throw();
extern "C" void func_002292A0(void *,int);
extern "C" void func_002ECDE0(void *);
extern "C" Module *func_002EC370(Module *,Obj *);
extern "C" void func_002EA590(void *,int);
extern "C" void *func_00305548(Obj *);
extern "C" int func_00306130(Obj *,void *);
extern "C" int func_0024E348(void *,Obj **);
extern "C" void func_003285A8(Obj *);
extern "C" void func_003285F8(Obj *);
extern "C" void func_0024E378(void *,int);
extern "C" void func_003041B8(void *,int);
struct Widget {
 Obj *p;
 Widget() { func_00229540(this); }
 Widget(const Widget &);
 ~Widget() {func_002292A0(this,2);}
};
struct Object {
 Obj *p;
 Object() { func_0030BB18(this); }
 Object(const Object &);
 ~Object() {func_00309378(this,2);}
};
struct Scope {
 Obj *p;
 Scope() {func_002ECDE0(this);}
 Scope(const Scope &);
 ~Scope() {func_002EA590(this,2);}
};
struct Module {
 Obj *p;
 Module() {}
 Module(const Module &);
 ~Module() {func_003041B8(this,2);}
};
struct Update {
 Obj *p;
 Update() {Obj *z=0; func_0024E348(this,&z);}
 Update(const Update &);
 ~Update() {func_0024E378(this,2);}
};
static inline void read(VE *e,Obj *o,Widget *w,const Object &obj) {
 e->fn(o,w,&obj);
}
static inline void assign(Obj **dst,const Update &u) {
 if(dst!=(Obj **)&u) {
  Obj *nv=u.p;
  if(nv) func_003285A8(nv);
  if(*dst) func_003285F8(*dst);
  *dst=nv;
 }
}
extern "C" void func_00219678(Self *self) {
 Obj **p=&self->p24;
 Iter it=func_003065B0(*p);
 Iter end=func_003065C8(*p);
 for(;it!=end;it++) {
  Widget w;
  Widget *pw=&w;
  {
   Obj *o=it->second;
   VE *e=(VE *)(o->vt+0x48);
   o=(Obj *)((char *)o+e->d);
   read(e,o,pw,Object());
  }
  {
   Obj *o=pw->p;
   VE *e=(VE *)(o->vt+0x2c8);
   o=(Obj *)((char *)o+e->d);
   e->fn(o,func_00213158(self));
  }
  {
   Obj *o=pw->p;
   VE *e=(VE *)(o->vt+0x2b8);
   o=(Obj *)((char *)o+e->d);
   e->fn(o,func_00213158(self));
  }
 }
 Obj **dst=&self->p20;
 {
  Obj *o=*p;
  VE *e=(VE *)(o->vt+0x10);
  e->fn((char *)o+e->d);
 }
 Module module;
 Module *p_module = &module;
 {
  Scope sc;
  Scope *ps=&sc;
  func_002EC370(p_module,ps->p);
 }
 Obj *m=p_module->p;
 func_00306130(m,func_00305548(*p));
 assign(dst,Update());
}
