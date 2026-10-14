/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring {char p0[0x38]; int lock; int p3c; int state;};
struct Obj {char p0[8]; Ring *ring;};
extern "C" int func_005ADCE0(int);
extern "C" void func_005ADCC0(int);
extern "C" int func_0054EFF8(void*,char**,int*,long*,long*);
extern "C" void func_00550038(void*,int*,int*,int*,int*);
extern "C" void *func_005A4724(void*,const void*,unsigned);
extern "C" void func_00550140(char*,int);
extern "C" int func_0054FBB8(Obj *obj,void *data) {
 long x,y; char *src; int len; int dst1,dst2,n1,n2;
 Ring *ring=obj->ring;
 func_005ADCE0(ring->lock);
 int state=ring->state;
 func_005ADCC0(ring->lock);
 if(state==0) return 1;
 if(state==3) return 3;
 func_0054EFF8(data,&src,&len,&x,&y);
 if(len==0) return 2;
 func_00550038(ring,&dst1,&n1,&dst2,&n2);
 if(n1+n2<len) return 3;
 if(n1>=len) {
  func_005A4724((void*)((dst1&0x0FFFFFFF)|0x20000000),src,len);
 } else {
  func_005A4724((void*)((dst1&0x0FFFFFFF)|0x20000000),src,n1);
  func_005A4724((void*)((dst2&0x0FFFFFFF)|0x20000000),src+n1,len-n1);
 }
 func_00550140((char*)ring,len);
 return 0;
}
