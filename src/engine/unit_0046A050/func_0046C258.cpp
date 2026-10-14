/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void*); };
extern "C" void func_0046C218(void*) throw();
extern "C" void func_0046C3E8(void*);
extern "C" void func_0046C418(void*);
extern "C" int func_0046C520(void*,int,int);
extern "C" int func_0046C6A8(void*);
extern "C" void func_0046C7F0(void*,int);
extern "C" void func_0046CBE8(void*);
extern "C" void func_00470DC0(void*);
extern "C" int func_00471F10(void*);
extern "C" int func_00471F50(void*);
#define I(p,o) (*(int*)((p)+(o)))
static inline int less(int a,int b) { return a<b; }
extern "C" int func_0046C258(char *self) {
 I(self,4)=1;
 int r=func_0046C6A8(self);
 if(r!=0) {
  char *state=self+0x85c;
  func_0046C3E8(self);
  VEntry *e=(VEntry*)(*(char**)(self+0x8e8)+0x10);
  e->fn(self+e->delta);
  func_0046C418(self);
  if(I(state,0x18)!=0) {
   func_0046C218(self);
   return 0;
  }
  {
   char *size=self+0x8c4;
   int y;
   int page=0;
   y=0;
   int dx=func_00471F10(size)*8;
   int dy=func_00471F50(size)*8;
   int count=I(self,0x8a8);
   int limited=count>0;
   if(less(y,I(self,0x88c))) do {
    for(int x=0;x<I(self,0x888);x+=dx) {
     r=func_0046C520(self,x,y);
     if(r==0) return r;
     if(limited) {
      --count;
      if(count<=0) {
       func_0046C7F0(self,page);
       page=(page+1)&7;
       count=I(self,0x8a8);
       func_00470DC0(self+0xc);
      }
     }
    }
    y+=dy;
   } while(y<I(self,0x88c));
   func_0046CBE8(self);
   if(I(state,0x18)!=0) {
    func_0046C218(self);
    return 0;
   }
   I(self,4)=2;
   return 1;
  }

 }
 return r;
}
