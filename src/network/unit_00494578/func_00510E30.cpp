struct Obj { char pad[0x40]; void *x; char pad44[0x24]; Obj *owner; Obj *next; };
struct Cfg { int count; int x; unsigned int size; void *a; void *b; void *c; };
#define F(p,o) (*(int *)((char *)(p)+(o)))
extern "C" int func_00538BF8(int *, unsigned long);
extern "C" int func_00538B08(int *, unsigned long);
extern "C" int func_00512120(int,int,int *);
extern "C" void func_00511050();
extern "C" void func_005110C0();
extern "C" void func_00510C80();
extern "C" void func_00510CD0();
extern "C" void func_00511708();
extern "C" int func_00510E30(int self,Cfg *cfg,int *count,Obj **out) {
 int p=0;
 if(self) {
 int r=1;
 if(F(self,0x68)==0 && cfg) {
  r=1;
  if(cfg->a) {
   r=1;
   if(cfg->b) {
    r=1;
    if(cfg->c) {
     r=1;
     if(cfg->size) {
      if(cfg->x) goto create;
      goto invalid;
     }
    }
   }
  }
 }
 return r;
 }
invalid:
 return 1;
create:
 *out=0;
 if(func_00538BF8(&p,0x70)==0) {
  F(p,0x68)=self;
  F(p,0x40)=(int)((Obj *)self)->x;
  F(p,0x3c)=cfg->count;
  F(p,0x44)=cfg->size;
  F(p,0x4c)=(int)cfg->a;
  F(p,0x50)=(int)cfg->b;
  F(p,0x54)=(int)cfg->c;
  F(p,0)= (int)func_00511050;
  F(p,4)= (int)func_005110C0;
  F(p,8)= (int)func_00510C80;
  F(p,12)= (int)func_00510C80;
  F(p,16)= (int)func_00510CD0;
  F(p,20)= (int)func_00510C80;
  F(p,24)= (int)func_00510C80;
  F(p,28)= (int)func_00510C80;
  F(p,32)= (int)func_00510C80;
  F(p,36)= (int)func_00511708;
  F(p,40)= (int)func_00510C80;
  F(p,44)= (int)func_00510C80;
  F(p,48)= (int)func_00510C80;
  F(p,52)= (int)func_00510C80;
  if(func_00538BF8((int *)(p+0x48),(unsigned long)(unsigned int)(F(p,0x3c)*8))==0) {
   if(func_00512120(*count,0,(int *)(p+0x64))==0) {
    int r=func_00538B08((int *)(p+0x60),(unsigned long)(unsigned int)F(p,0x44));
    if(r==0) {
     F(p,0x6c)=(int)((Obj *)self)->next;
     ((Obj *)self)->next=(Obj *)p;
     *out=(Obj *)p;
     return r;
    }
   }
  }
 }
 ((void (*)(int))F(p,16))(p);
 return 2;
}
