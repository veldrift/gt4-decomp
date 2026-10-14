/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {char pad[0x108];int value;char pad2[16];int old,count;};
struct Event {char pad[32];int key;char pad2[12];int repeat;};
struct Handle {void *p;char pad[12];};
extern "C" void func_0023DDF0(Handle *,int);
extern "C" void func_0023F8C8(void *,const char *);
extern "C" void func_0023FB80(Handle *);
extern "C" int mWidget__onKeyPress(Obj *,int,Event *);
extern "C" int func_00265FE0(Obj *);
extern "C" void func_002A4768(Obj *,int) throw();
extern "C" void func_0057CE40(int *,int);
extern "C" void func_0057CF10(int *,int);
extern char D_0069B928[];
extern "C" int mInputNumberFace__onKeyPress(Obj *self,int arg1,Event *e) {
 int handled=1;int key=e->key;
 if(e->repeat)self->count++;else self->count=0;
 Handle h;
 if(func_00265FE0(self)){
  if(key==0xFF0D||key==0xFF8D){func_002A4768(self,0);self->old=self->value;}
  else if(key==0xFF1B){func_002A4768(self,0);func_0057CE40(&self->value,self->old);}
  else if(key==0xFF52||key==0xFF97){
   func_0023FB80(&h);func_0023F8C8(h.p,D_0069B928);func_0023DDF0(&h,2);
   int n=self->count;
   if(n>=41)func_0057CF10(&self->value,100);
   else if(n>=16)func_0057CF10(&self->value,10);
   else func_0057CF10(&self->value,1);
  }
  else if(key==0xFF54||key==0xFF99){
   func_0023FB80(&h);func_0023F8C8(h.p,D_0069B928);func_0023DDF0(&h,2);
   int n=self->count;
   if(n>=41)func_0057CF10(&self->value,-100);
   else if(n>=16)func_0057CF10(&self->value,-10);
   else func_0057CF10(&self->value,-1);
  }
  else if((unsigned)(key-0x30)<10)func_0057CE40(&self->value,self->value*10+key-0x30);
  else if(key==0xFF08)func_0057CE40(&self->value,self->value/10);
  else handled=0;
 }else if(key==0xFF0D||key==0xFF8D){func_002A4768(self,1);self->old=self->value;}
 else handled=0;
 int result=2;if(!handled)result=mWidget__onKeyPress(self,arg1,e);return result;
}
