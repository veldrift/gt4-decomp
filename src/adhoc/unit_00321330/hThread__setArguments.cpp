/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int pad; void **start; void **finish; };
struct Self { char pad[0x2c]; Vec *values; };
struct Temp { void *p; int pad[3]; };
struct Value { int pad[4]; Value() __asm__("func_0030BB18"); ~Value() __asm__("func_00309378"); };
extern "C" {
void func_00301228(void *,int);
Temp *func_00301828(void *,void *,void *);
void func_003285A8(void *);
void func_003285F8(void *);
}
static inline void assign(void **dst, void **src) {
 if(dst!=src) {
  void *p=*src;
  if(p) func_003285A8(p);
  if(*dst) func_003285F8(*dst);
  *dst=p;
 }
}
static inline void put(Self *self,Vec *names,int i,void **args) {
 Vec *v=self->values;
 Temp t;
 func_00301828(&t,names->start+i,args+i);
 assign(v->start+i,&t.p);
 func_00301228(&t,2);
}
extern "C" void hThread__setArguments(Self *self,Vec *names,int argc,void **args,void **last) {
 int n=names->finish-names->start;
 if(n>0) {
  if(n==argc) {
   for(int i=0;i<n;i++) put(self,names,i,args);
  } else if(argc<n) {
   int i=0;
   for(;i<argc;i++) put(self,names,i,args);
   for(;i<n;i++) {
    Vec *v=self->values;
    void **name=names->start+i;
    Temp t;
    Value val;
    func_00301828(&t,name,&val);
    assign(v->start+i,&t.p);
    func_00301228(&t,2);
   }
  } else if(n<argc) {
   for(int i=0;i<n;i++) put(self,names,i,args);
  }
 }
 assign(self->values->start+n,last);
}
