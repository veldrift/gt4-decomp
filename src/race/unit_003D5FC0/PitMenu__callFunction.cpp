/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
typedef unsigned int u32;
extern "C" {
void func_0035BF08(void *,unsigned char,unsigned char,int,int);
int func_003DCF10(const char *) throw();
char *func_003DCF88(const char *) throw();
int func_003DD6D8(void *);
int func_003DD720(void *);
char *func_00407AC0(void *,int);
char *func_00407B70(void *,int);
char *func_00407D00(void *);
int func_00476768(void *,void *);
void func_004768C0(void *);
void func_00476AE8(void *,const char *);
char *strobe__Any__toString(void *);
float func_00477460(void *);
void func_00480F78(void *);
void func_00480FA0(void *,int);
void func_004857C8(const char *);
int func_0057F260(const char *) throw();
int func_005FBDD0(void *,const char *,u32,u32);
}
extern char D_006A3578[],D_006A3588[],D_006A3598[],D_006A35A0[],D_006A35B0[],D_006A35B8[],D_006A35C8[],D_006A35D8[],D_006A35E8[],D_006A35F0[],D_006A3600[];
extern char *D_00621C94;
struct Value { int tag; float val; char pad[8]; Value(){tag=1;} Value(int n){tag=6;val=(float)n;} Value(const Value &v){func_00476768(this,(void *)&v);} ~Value(){func_004768C0(this);} void assign(const char *s){func_00476AE8(this,s);} };
static inline bool eq(void *s,const char *t){return func_005FBDD0(s,t,0,func_0057F260(t))==0;}
static inline void *top(void *s){return F(s,char *,8)-8;}
static inline void number(void *r,int n){F(r,int,0)=6;F(r,float,4)=(float)n;}
extern "C" Value PitMenu__callFunction(char *self,void *name,int count,void *stack){
 if(eq(name,D_006A3578)){
  func_004857C8(strobe__Any__toString(top(stack)));
 }else if(eq(name,D_006A3588)){
  F(self,int,0xe0)=0;
 }else if(eq(name,D_006A3598)){
  int a=func_003DD6D8(self);
  int b=func_003DD720(self);
  int mode=255;
  if(F(self,int,0x100)) mode=F(self,int,0xfc)!=0;
  func_0035BF08(F(F(self,void *,0xd8),void *,0x18),a<0?255:(a&255),b<0?255:(b&255),F(self,int,0xf8),mode);
  F(self,int,0xdc)=0;
 }else if(eq(name,D_006A35A0)){
  int item=func_003DCF10(strobe__Any__toString(top(stack)));
  func_00480F78(stack); count--;
  int n=(int)func_00477460(top(stack));
  func_00480FA0(stack,count);
  Value v;
  if(item==0){
   char *p=self+0x10;
   if(F(self,int,0xe8)){
    if(n!=F(p,int,0x44)) v.assign(func_00407AC0(p,n));
    else v.assign(func_00407D00(p));
   }else v.assign(D_00621C94);
  }else if(item==1){
   if(F(self,int,0xe8)){
    char *p=self+0x10;
    if(n==F(self,int,0xa0))v.assign(func_00407D00(p));
    else v.assign(func_00407B70(p,n));
   }else v.assign(D_00621C94);
  }else if(item==2){
   if(F(self,int,0xec))v.assign(func_003DCF88(n==1?D_006A35B0:D_006A35B8));
   else v.assign(D_00621C94);
  }else{
   if(!F(self,int,0x100))v.assign(D_00621C94);
   else v.assign(func_003DCF88(n==1?D_006A35C8:D_006A35D8));
  }
  return v;
 }else if(eq(name,D_006A35E8)){
  int item=func_003DCF10(strobe__Any__toString(top(stack)));
  func_00480FA0(stack,count);
  int n;
  if(item==0)n=F(self,int,0xe8)?F(self,int,0x54)+1:1;
  else if(item==1)n=F(self,int,0xe8)?F(self,int,0xa0)+1:1;
  else if(item==2)n=F(self,int,0xec)?2:1;
  else n=F(self,int,0x100)?2:1;
  return Value(n);
 }else if(eq(name,D_006A35F0)){
  int item=func_003DCF10(strobe__Any__toString(top(stack)));
  func_00480FA0(stack,count);
  int n;
  if((u32)item<2)n=F(self+item*4,int,0xf0);
  else if(item==2)n=F(self,int,0xf8)!=0;
  else n=(F(self,int,0x100)&&F(self,int,0xfc))?1:0;
  return Value(n);
 }else if(eq(name,D_006A3600)){
  count--;
  int item=(int)func_00477460(top(stack));
  func_00480F78(stack);
  int n=(int)func_00477460(top(stack));
  if((u32)item<2)F(self+item*4,int,0xf0)=n;
  else if(item==2)F(self,int,0xf8)=n!=0;
  else F(self,int,0xfc)=n!=0;
 }
 func_00480FA0(stack,count);
 return Value();
}
