/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val;
extern "C" int func_00476768(void *,void *);
extern "C" void func_004768C0(void *);
struct Val { int kind; char data[12];
 Val() {kind=1;}
 Val(const Val &v) {func_00476768(this,(void *)&v);}
 ~Val() {func_004768C0(this);}
};
struct Args { int a,b; char *end; };
struct VEntry { short delta,index; void (*fn)(void *,int,float,float); };
struct Menu { char pad[0x64]; VEntry *vt; };
struct Parent { char pad[0x84]; Menu *menu; char rest[0x6c]; };
struct Obj { char pad[0x4f8]; Parent *parent; char tail[0x74]; int prize; };
extern char D_006A3838[],D_006A3848[],D_006A3858[],D_006A3860[],D_006A3870[],D_006A3880[],D_006A3888[],D_006A3898[],D_006A38A8[],D_006A38B8[];
extern "C" {
void func_003B76F0(void *,int,int,int); int func_00476768(void *,void *); void func_004768C0(void *);
void func_00476AE8(void *,void *); void func_00476B78(void *,float); char *strobe__Any__toString(void *);
void func_00480FA0(void *,int); void func_004857C8(char *);
int func_0057F238(const char *,const char *) throw(); unsigned func_0057F260(const char *) throw();
int func_005FBDD0(void *,const char *,unsigned,unsigned);
}
extern "C" Val ResultLicense__callFunction(Obj *self,void *name,int n,Args *args) {
 if(func_005FBDD0(name,D_006A3838,0,func_0057F260(D_006A3838))==0) {
  func_004857C8(strobe__Any__toString(args->end-8));
 } else if(func_005FBDD0(name,D_006A3848,0,func_0057F260(D_006A3848))==0) {
  if(n) {
   if(func_0057F238(strobe__Any__toString(args->end-8),D_006A3858)==0) {
    Menu *m=self->parent->menu; VEntry *e=(VEntry *)((char *)m->vt+0x2b8);
    e->fn((char *)m+e->delta,4,0.0f,0.0f);
   } else func_003B76F0((char *)self->parent+0xf4,1,0,0);
  }
 } else if(func_005FBDD0(name,D_006A3860,0,func_0057F260(D_006A3860))==0) {
  Val t; t.kind=1;
  switch(self->prize) {
   case 1: case 2: func_00476B78(&t,0.0f); break;
   case 3: func_00476B78(&t,1.0f); break;
   case 4: case 5: func_00476B78(&t,2.0f); break;
   default: func_00476B78(&t,3.0f); break;
  }
  func_00480FA0(args,n); return t;
 } else if(func_005FBDD0(name,D_006A3870,0,func_0057F260(D_006A3870))==0) {
  func_00480FA0(args,n); Val t; t.kind=1; func_00476AE8(&t,(char *)self+0x544);
  return t;
 } else if(func_005FBDD0(name,D_006A3880,0,func_0057F260(D_006A3880))==0) {
  func_00480FA0(args,n); Val t; t.kind=1; func_00476AE8(&t,(char *)self+0x6c);
  return t;
 } else if(func_005FBDD0(name,D_006A3888,0,func_0057F260(D_006A3888))==0) {
  func_003B76F0((char *)self->parent+0xf4,22,0,0);
 } else if(func_005FBDD0(name,D_006A3898,0,func_0057F260(D_006A3898))==0) {
  func_00480FA0(args,n); Val t; t.kind=1; func_00476AE8(&t,(char *)self+0x500);
  return t;
 } else if(func_005FBDD0(name,D_006A38A8,0,func_0057F260(D_006A38A8))==0) {
  func_00480FA0(args,n); Val t; t.kind=1;
  void *s=*(void **)((char *)self+0x540); if(!s)s=D_006A38B8;
  func_00476AE8(&t,s); return t;
 }
 func_00480FA0(args,n); return Val();
}
