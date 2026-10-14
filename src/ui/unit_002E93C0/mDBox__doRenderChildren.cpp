/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0xc8]; int n,count; };
extern "C" void func_002E9600(void*,float*,float*,float*,float*) throw();
extern "C" void func_002E96C0(void*,float*,float*) throw();
extern "C" float func_002E9790(void*) throw();
extern "C" float func_002E97B8(void*) throw();
extern "C" float func_002E94E0(void*) throw();
extern "C" void *func_00206868(void*);
extern "C" void func_00263C40(void*);
extern "C" int func_002073D8(void*,void*);
extern "C" void func_002E97E0(void*,void*,float*,float*) throw();
extern "C" int func_002E9540(void*,void*) throw();
extern "C" int func_002E95A0(void*,void*) throw();
extern "C" int func_002E9570(void*,void*) throw();
extern "C" int func_002E95D0(void*,void*) throw();
extern "C" int func_00266338(void*);
extern "C" void func_002E9830(void*,void*,float,float,float,float) throw();
extern "C" void func_00207378(void*,void*,void*);
extern "C" void *func_0025C300(void*);
extern "C" void mDBox__doRenderChildren(S *self,void *ctx) {
 float l,r,t,b,w,h;
 float *pw,*ph;
 float extra=0.0f;
 func_002E9600(self,&l,&r,&t,&b);
 pw=&w; ph=&h;
 func_002E96C0(self,pw,ph);
 if(self->count>0) extra=(func_002E9790(self)-w)/(float)self->count;
 float height=func_002E97B8(self)-(t+b);
 float space;
 if(self->n>=2) space=func_002E94E0(self); else space=0.0f;
 float left=l;
 float right=func_002E9790(self)-r;
 float top=t;
 void *child=func_00206868(self);
 if(child) {
  do {
   func_00263C40(child);
   if(func_002073D8(self,child)) {
    func_002E97E0(self,child,pw,ph);
    float dy=0.0f;
    float dx=0.0f;
    float cw=w;
    if(func_002E9540(self,child)) {
     cw=w+extra;
     if(func_002E95A0(self,child)) w+=extra; else dx=extra*0.5f;
    }
    if(func_002E9570(self,child)) {
     if(func_002E95D0(self,child)) h=height; else dy=(height-h)*0.5f;
    }
    if(func_00266338(child)) {
     func_002E9830(self,child,(right-cw)+dx,top+dy,w,h);
     right-=cw+space;
    } else {
     func_002E9830(self,child,left+dx,top+dy,w,h);
     left+=cw+space;
    }
   }
   func_00207378(self,ctx,child);
   child=func_0025C300(child);
  } while(child);
 }
}
