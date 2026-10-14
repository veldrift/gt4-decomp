/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Vec { float x,y,z; };
struct Rep { int len,cap,ref,sel; };
struct Holder { void *p; char pad[12]; };
struct VObj { char pad[4]; char *vt; };
struct Entry { short delta,index; int (*fn)(void*); };
struct Self { char pad0[0x2B8]; char *name; VObj *obj; void *slot[2]; char *name2; VObj *obj2; void *slot2[2]; char *name3; void *obj3; int x2e0; Vec pos,rot; char pad1[0xc]; int flags; };
extern "C" void mTextFace__virtual_67(void*);
extern "C" Vec *func_0021A820(void*);
extern "C" Vec *func_0021A850(void*);
extern "C" void func_0025A7E0(void*,void*);
extern "C" void func_0026A848(void*,void*,void*,int,int,int);
extern "C" void func_0026A990(void*,void*,void*,int,int,int);
extern "C" void func_0026AC20(void*,void*,void*,int,int,int);
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
extern "C" void func_0021B5D0(void*,int);
extern "C" void func_00210710(void*,int);
extern "C" void func_0021B340(void*,int);
extern "C" void func_0026A118(void*,int);
extern "C" void func_0021A7A0(void*,void*);
extern "C" void func_0021A7B0(void*,void*);
extern "C" void func_0021A7D0(void*,void*);
extern "C" void func_0021A7E0(void*,void*);
extern "C" void func_0021A7F0(void*,float);
extern "C" void func_0021A800(void*,int);
extern "C" void func_0021A810(void*,int);
extern "C" void func_0021A828(void*,Vec*);
extern "C" void func_0021A858(void*,Vec*);
static inline int vc(VObj *o,int off) { Entry *e=(Entry*)(o->vt+off); return e->fn((char*)o+e->delta); }
static inline void assign(void **dst,Holder *src) { if(dst!=&src->p) { void *nv=src->p; if(nv)func_003285A8(nv); if(*dst)func_003285F8(*dst); *dst=nv; } }
extern "C" void mModelFace__virtual_67(Self *self) {
 char *model=(char*)self+0xA0;
 char **np=&self->name;
 Vec *pos=&self->pos,*rot=&self->rot;
 mTextFace__virtual_67(self);
 Vec *v=func_0021A820(model); pos->x=v->x;pos->y=v->y;pos->z=v->z;
 Vec *v2=func_0021A850(model);rot->x=v2->x;rot->y=v2->y;rot->z=v2->z;
 VObj *obj=self->obj;
 Holder sp0,h1,h2,h3;
 if(((Rep*)*np)[-1].len && (!obj || !vc(obj,0x48))) {
  Holder *ph=&h1;
  void **dst=(void**)((char*)self+(((u32)self->flags>>3)&4)+0x2C0);
  func_0025A7E0(ph,self);
  func_0026A848(&sp0,ph->p,np,(self->flags>>2)&1,(self->flags>>3)&1,(self->flags>>4)&1);
  assign(dst,&sp0);func_0021B5D0(&sp0,2);func_0026A118(ph,2);
  obj=*(VObj**)((char*)self+(((u32)self->flags>>3)&4)+0x2C0);
 }
 np=&self->name2;
 if(((Rep*)*np)[-1].len && (!self->obj2 || !vc(self->obj2,0x58))) {
  Holder *ph=&h2;
  void **dst=(void**)((char*)self+(((u32)self->flags>>7)&4)+0x2D0);
  func_0025A7E0(ph,self);
  func_0026A990(&sp0,ph->p,np,(self->flags>>6)&1,(self->flags>>7)&1,(self->flags>>8)&1);
  assign(dst,&sp0);func_00210710(&sp0,2);func_0026A118(ph,2);
  self->obj2=*(VObj**)((char*)self+(((u32)self->flags>>7)&4)+0x2D0);
 }
 np=&self->name3;
 if(((Rep*)*np)[-1].len) {
  Holder *ph=&h3;void **dst=&self->obj3;
  func_0025A7E0(ph,self);func_0026AC20(&sp0,ph->p,np,1,0,1);
  assign(dst,&sp0);func_0021B340(&sp0,2);func_0026A118(ph,2);
 }
 if(obj) {
  func_0021A7A0(model,(char*)self+0xEC);func_0021A7B0(model,(char*)self+0x154);
  func_0021A7D0(model,self->obj2);func_0021A7E0(model,obj);func_0021A7F0(model,1.0f);
  func_0021A800(model,0);func_0021A810(model,self->x2e0);func_0021A828(model,pos);func_0021A858(model,rot);self->obj=obj;
 }
}
