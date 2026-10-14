/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,o) (*(int *)((char *)(p)+(o)))
struct Item { char pad[0x24]; char name[0x11]; signed char type; };
extern "C" char *func_005030E8();
extern "C" void func_004F82E8(char *) throw();
extern "C" int func_004F8348(char *,const char *) throw();
extern "C" int func_004F9E60(char *,int);
extern "C" int func_004F9E90(char *,int);
extern "C" Item *func_004F9F18(char *,int);
extern "C" int func_004FA178(char *,int);
extern "C" void func_005015C0(char *,int,int);
extern "C" void func_005015F8(char *,int,int);
extern "C" void func_00501630(char *,int,int);
extern "C" void func_00501668(char *,int,int);
extern "C" void func_005016A0(char *,int,int);
extern "C" int func_004F83E8(char *self) {
 int i=0;
 int selected=-1;
 int type=-1;
 char *manager=func_005030E8();
 func_004F82E8(self);
 int found=0;
 int id=func_004F9E60(self,F(self,0xcc4));
 for(;i<F(self,0xee0);i++) {
  int a=func_004FA178(self,i);
  int b=func_004F9E90(self,a);
  if(a!=-1 && b!=-1) func_005015F8(manager,a,b);
 }
 for(i=0;i<F(self,0xee0);i++) {
  Item *item=func_004F9F18(self,i);
  if(item && item->type==0) {
   int a=func_004FA178(self,i);
   func_005015C0(manager,a,0);
   func_00501630(manager,a,F(self,0x3f68));
   if(a==id) {
    int n=F(self,0x3f68);
    found=1; type=0;
    F(self,0x3fa0)=n; F(self,0x3fa4)=n; F(self,0x3fa8)=n;
   }
   int *count=(int *)(self+0x3f68);
   char *base=self+8;
   int n=*count;
   F(base+n*4,0x3f40)=i;
   *count=n+1;
   F(self,0x3f44)++;
  }
 }
 int j=0;
 int k=0;
 for(;k<F(self,0xee0);k++) {
  Item *item=func_004F9F18(self,k);
  if(item && item->type==1) {
   int a=func_004FA178(self,k);
   int n=func_004F8348(self,item->name);
   if(n<0) n=0;
   if(a==id) {
    type=1;F(self,0x3fa4)=n;selected=j;
    F(self,0x3fa0)=-1;F(self,0x3fa8)=F(self,0x3f68);
   }
   if(found) {
    func_005015C0(manager,a,1);
    func_005016A0(manager,a,j);
    int *count=(int *)(self+0x3f9c);
    char *base=self+12;
    int n=*count;
    F(base+n*4,0x3f60)=k;
    *count=n+1;
   }
   j++;
  }
 }
 for(k=0;k<F(self,0xee0);k++) {
  Item *item=func_004F9F18(self,k);
  if(item && item->type==2) {
   int a=func_004FA178(self,k);
   int n=func_004F8348(self,item->name);
   if(n<0) n=0;
   if(a==id) { F(self,0x3fa0)=n;F(self,0x3fa4)=n;type=1;F(self,0x3fa8)=-1; }
   if(found) {
    func_005015C0(manager,a,1);
    func_00501668(manager,a,n);
    int *count=(int *)(self+0x3f9c);
    char *base=self+12;
    int n=*count;
    F(base+n*4,0x3f60)=k;
    *count=n+1;
   }
  }
 }
 int n=F(self,0x3fa0);
 char *p=manager+0xb8;
 if(n>=0) F(p,0x34)=n;
 F(p,0x3c)=selected;
 F(p,0x40)=type;
}
