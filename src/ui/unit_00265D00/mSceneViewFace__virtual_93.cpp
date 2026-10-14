/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Heap {const char *name;};
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,int,const char *);
struct Rep {
 u32 len,res,ref,selfish;
 char *data(){return (char *)(this+1);}
 char *grab();
 static void operator delete(void *p,u32 n){func_00326798(p,n,4,func_005C11A8()->name);}
 void release(){if(--ref==0)operator delete(this,sizeof(Rep)+res);}
};
extern "C" char *func_005C2560(Rep *);
inline char *Rep::grab(){if(selfish)return func_005C2560(this);++ref;return data();}
struct String {
 char *dat;
 Rep *rep()const{return (Rep *)dat-1;}
 String(const String &s):dat(s.rep()->grab()){}
 ~String(){rep()->release();}
 bool empty()const{return rep()->len==0;}
 String &operator=(const String &s){if(&s!=this){rep()->release();dat=s.rep()->grab();}return *this;}
};
struct Entry {short delta,pad;int (*fn)(void *);};
struct Rects {float x,y,z,w,x2,y2,z2,w2;int flags;};
static inline u32 nibble(u32 value,int shift){return (value>>shift)&15;}
struct Obj {int x;Entry *vt;char pad[0x88];Rects *rect;String name;u32 state,flags;};
extern "C" Obj *func_00206868(void *);
extern "C" void func_002189C8(void *,const String *);
extern "C" Rects *func_00254FD0() throw();
extern "C" void mWidget__getWindowSize(void *,float *,float *) throw();
extern "C" void func_0025BF90(void *) throw();
extern "C" int func_0025C2A0(void *) throw();
extern "C" Obj *func_0025C300(void *) throw();
extern "C" void func_00265E50(void *,int) throw();
extern "C" int func_00265EA8(void *) throw();
extern "C" void func_00266900(void *,int) throw();
extern "C" int func_00267698(void *) throw();
extern "C" String func_00268888(void *);
extern "C" String func_0030D700(const String &);
extern "C" void mSceneViewFace__virtual_93(Obj *self){
 float size[2];
 func_00266900(self,0);
 if(func_00267698(self)==2 || (func_00267698(self)==1 && func_0025C2A0(self))){
  mWidget__getWindowSize(self,size,size+1);
  if(self->rect){
   if(self->rect->flags&1){
    self->rect->flags&=~1;
    if(size[0]>0.0f){self->rect->x/=size[0];self->rect->z/=size[0];}
    if(size[1]>0.0f){self->rect->y/=size[1];self->rect->w/=size[1];}
   }
   if(self->rect->flags&2){
    self->rect->flags&=~2;
    if(size[0]>0.0f){self->rect->x2/=size[0];self->rect->z2/=size[0];}
    if(size[1]>0.0f){self->rect->y2/=size[1];self->rect->w2/=size[1];}
   }
  }else if(func_00265EA8(self))self->rect=func_00254FD0();
 }
 if(self->flags&0x100){
  self->flags&=~0x100;
  u32 state=self->state;
  if(!(state&0xFF0))func_00265E50(self,0);
  else if(nibble(state,4)&~nibble(state,8)){
   func_00265E50(self,1);
   self->state&=~0xF0;
   self->state&=~0xF00;
  }
 }
 Entry *v=self->vt+54;
 if(v->fn((char *)self+v->delta)){
  for(Obj *n=func_00206868(self);n;n=func_0025C300(n)){
   Entry *e=n->vt+94;((void (*)(void *))e->fn)((char *)n+e->delta);
  }
 }
 func_0025BF90(self);
 String s=func_00268888(self);
 if(!s.empty()){
  s=func_0030D700(s);
  func_002189C8(self,&s);
 }
}
