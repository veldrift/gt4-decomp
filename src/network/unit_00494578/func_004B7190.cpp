/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004B4220() throw();
extern "C" int func_004B4B40(void *,int) throw();
extern "C" void func_004B54E8(void *) throw();
extern "C" void func_004B5628(void *) throw();
extern "C" void func_004B5B38(void *,void *) throw();
extern "C" void func_004B61A8(char *) throw();
extern "C" void func_0057D9C0(const char *,...);
extern char D_006B0458[];
struct E {signed char flag;char pad[7];};
struct B {int state;char pad[0x210];int count;E e[64];int tail;};
#define I(p,o) (*(int *)((p)+(o)))
extern "C" int func_004B7190(char *self) {
 if(I(self,0x860))return 1;
 B *b=(B *)(self+(1-I(self,0x858))*0x41c+0x20);
 switch(b->state) {
 case 0:return 0;
 case 1:
  if(func_004B4B40(self,1)<=0) {
   func_004B5628(self);
   b->state=0;
  } else {
   for(int j=0;j<2;j++) {
    for(int i=0;i<b->count;i++) {
     E *e=&b->e[i];
     if(e->flag==1) {func_004B5B38(self,e);break;}
    }
   }
   b->tail=0;
   func_004B61A8(self);
  }
  return 1;
 case 2: {
  func_004B54E8(self);
  int r=func_004B4220();
  if(r<0) func_0057D9C0(D_006B0458,r&255,r&0x7f00);
  b->state=1;
  return 1;
 }
 default:return 1;
 }
}
