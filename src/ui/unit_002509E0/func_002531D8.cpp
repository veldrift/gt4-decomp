/* compiler: ee-gcc2.96-no-strict-aliasing */
struct EntryI { short delta,index; int (*fn)(void *,int); };
struct EntryF { short delta,index; float (*fn)(void *,int,int); };
struct EntryV { short delta,index; void (*fn)(void *); };
struct Obj { int ref; char *vt; char pad[0xd8]; int idle; };
struct Window { char pad[0x6e4]; int active,flags; };
struct Handle { void *p; int pad[3]; };
extern "C" int func_00251BD0(Obj *) throw();
extern "C" Window *func_00251BD8(Obj *,int) throw();
extern "C" void *func_002319C0(Window *);
extern "C" void func_00230EC0(Window *,float *,float *);
extern "C" int func_002320F0(Window *);
extern "C" int func_00232230(Window *,int);
extern "C" int mKeyPressEvent__structor_1(Obj *,int,Window *,void *) throw();
extern "C" int mButtonPressEvent__structor_0(Obj *,int,Window *,void *) throw();
extern "C" void *func_0022F1F0(Window *);
extern "C" void *func_0022F350(Window *);
extern "C" void func_002BFA70(Handle *,Window *,void *,float,float);
extern "C" void func_00250CE0(Obj *,Handle *) throw();
extern "C" void func_002BF4E8(Handle *,int);
extern "C" void func_00251048(Obj *,int,int) throw();
extern "C" void func_00251058(Obj *,int,int,float) throw();
static inline int buttons(Obj *o,int i) { EntryI *e=(EntryI *)(o->vt+0x1d8); return e->fn((char*)o+e->delta,i); }
static inline float axis(Obj *o,int i,int j) { EntryF *e=(EntryF *)(o->vt+0x1e0); return e->fn((char*)o+e->delta,i,j); }
extern "C" void func_002531D8(Obj *self) {
 float x,y,x2,y2;
 Handle h;
 int changed=0;
 int k=0;
 int n=func_00251BD0(self);
 for(;k<n;k++) {
  Window *w=func_00251BD8(self,k);
  if(w->active) {
   void *obj=func_002319C0(w);
   if(obj) {
    int flags=w->flags;
    func_00230EC0(w,&x,&y);
    if(flags&1) {
     if(func_002320F0(w)) { if(func_00232230(w,0)) changed=1; }
     else { if(mKeyPressEvent__structor_1(self,0,w,obj)) changed=1; }
    }
    if(flags&2) {
     if(func_002320F0(w)) { if(func_00232230(w,1)) changed=1; }
     else { if(mKeyPressEvent__structor_1(self,1,w,obj)) changed=1; }
    }
    if(flags&4) { if(mButtonPressEvent__structor_0(self,0,w,obj)) changed=1; }
    if(flags&0x10) {
     func_00230EC0(w,&x2,&y2);
     if((int)x!=(int)x2 || (int)y!=(int)y2) {
      void *target=func_0022F1F0(w);
      if(!target) target=func_0022F350(w);
      if(target) {
       changed=1;
       func_002BFA70(&h,w,target,x2,y2);
       func_00250CE0(self,&h);
       func_002BF4E8(&h,2);
      }
     }
    }
   }
  }
 }
 for(int i=0;i<2;i++) {
  func_00251048(self,i,buttons(self,i));
  for(int j=0;j<4;j++) func_00251058(self,i,j,axis(self,i,j));
 }
 if(changed) self->idle=0;
 else self->idle++;
 EntryV *e=(EntryV*)(self->vt+0x1a8);
 e->fn((char*)self+e->delta);
}
