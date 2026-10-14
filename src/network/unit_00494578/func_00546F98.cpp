/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx { char data[0x38]; int v38,v3c; char digest[20]; int flag,lo,hi; };
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" void func_006C5400(Ctx *);
extern "C" void func_006C7350(Ctx *,int,int);
extern "C" void func_006C7380(void *,void *,unsigned int);
extern "C" void func_00546F98(Ctx *c,char *out,unsigned int len) {
 int idx=c->lo;
 idx=(idx>>3)&63;
 char *p=(char *)c+idx;
 idx=63-idx;
 *p=-128;
 p++;
 if(idx<8) {
  func_005A48D8(p,0,idx);
  func_006C7350(c,64,c->flag);
  func_006C5400(c);
  func_005A48D8(c,0,56);
 } else {
  func_005A48D8(p,0,idx-8);
 }
 c->v38=c->hi;
 c->v3c=c->lo;
 func_006C7350(c,56,c->flag);
 func_006C5400(c);
 if(len>=21u) {
  func_005A48D8(out+20,0,len-20);
  len=20;
 }
 func_006C7380(out,c->digest,len);
 *(int *)c=0;
}
