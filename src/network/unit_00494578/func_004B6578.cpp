/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int f0; int f4; char pad[8]; int count; unsigned short *data; };
extern "C" int func_004B4628(unsigned short *,int,int,int,unsigned short *) throw();
static inline void set(int n, unsigned short *p) {
 if(n>0) *p |= 0x80; else *p &= 0x7f;
}
extern "C" void func_004B6578(Obj *o,int value,int mode,int n) {
 unsigned short tmp[2];
 tmp[0]=value; tmp[1]=0;
 func_004B4628(o->data,o->f4,o->count,0,tmp);
 o->count++;
 if(mode==2) {
  set(n,o->data+o->count-3);
  set(--n,o->data+o->count-2);
  set(--n,o->data+o->count-1);
 } else if(mode==1) {
  set(n,o->data+o->count-2);
  set(--n,o->data+o->count-1);
 } else if(mode==0) {
  set(n,o->data+o->count-1);
 }
}
