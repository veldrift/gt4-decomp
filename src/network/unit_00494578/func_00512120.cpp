extern "C" int func_00538BF8(int *,int);
extern "C" int func_00538B08(int *,unsigned long);
extern "C" int func_00512268(int);
#define F(p,o) (*(int *)((char *)(p)+(o)))
extern "C" int func_00512120(int count,int size,int *out) {
 int sp[4]; int e;
 int r=func_00538BF8(sp,0x1c);
 if(r==0) {
  F(sp[0],0)=count;
  F(sp[0],8)=size;
  F(sp[0],4)=size+16;
  F(sp[0],12)=F(sp[0],0)*F(sp[0],4);
  int n=F(sp[0],12);
  if(n) {
   e=func_00538B08((int *)((char *)sp[0]+16),(unsigned long)(unsigned int)n);
   if(e!=0) goto error;
   {
    unsigned int last=count-1, i=0;
    int p=F(sp[0],16);
    for(;i<last;i++) {
     F(p,8)=p+F(sp[0],4);
     if(size) F(p,0)=p+16; else F(p,0)=0;
     p=F(p,8);
    }
    F(p,8)=0;
    if(size) F(p,0)=p+16; else F(p,0)=0;
   }
  } else F(sp[0],16)=0;
  F(sp[0],20)=F(sp[0],16);
  *out=sp[0];
  return 0;
 }
 return r;
error:
 func_00512268(sp[0]);
 return e;
}
