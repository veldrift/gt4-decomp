/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct State {
 unsigned char flag; char p1[2]; unsigned char mode;
 char p4[0x10]; int count; char p18[8]; float value;
 char p24[0x1c]; int color; char p44[6]; unsigned short flags;
 char p4c[0x18c]; unsigned long a; char p1e0[8]; unsigned long b;
 char p1f0[8]; unsigned *cursor; char p1fc[0xe2c]; int frame;
};
extern unsigned char D_70002000[];
extern unsigned char D_00624C70;
extern unsigned D_0084AF30;
extern int D_0084AF34;
extern unsigned char D_0084AF40[];
extern "C" void func_0049E480(State *);
extern "C" void func_0049E548(State *, int, float);
extern "C" void func_0049E5F8(State *, int);
static inline State *get(State *const &p) { return p; }
extern "C" void func_0049BBF0() {
 State *s=get((State *)spr_base());
 if(D_00624C70) {
  D_00624C70=0;
  if(D_0084AF30) {
   s->frame++;
   if(s->flag) func_0049E480(s);
   int n=s->count;
   if(!s->mode || s->value!=0.0f) {
    --n;
    func_0049E548(s,0xc1,0.0f);
    s->mode=1;
   }
   if(s->a & s->b) {
    func_0049E5F8(s,0xd9);
    n-=5;
   }
   unsigned *p=s->cursor; unsigned *start=p;
   unsigned f=s->flags | 4;
   ++p; *p++=0;
   if(s->color!=0x3f3f3f3f) {
    *p++=0x20000000; *p++=0x3f3f3f3f;
    s->color=0x3f3f3f3f;
   }
   *p++=((D_0084AF34+1)<<16)|0x7200c040;
   unsigned char *q=(unsigned char *)p;
   *q++=D_0084AF34;
   for(int i=0;i<D_0084AF34;i++) *q++=D_0084AF40[i]*3-6;
   p=(unsigned *)(((unsigned)q+3)&~3);
   *p++=0x6801c0c0;
   *p++=D_0084AF30|0x8000;
   *p++=(f<<15)|0x30004000;
   *p++=0x412;
   *p++=n|0x14000000;
   while((unsigned)p&15) *p++=0;
   *start=(((unsigned)((char *)p-(char *)start)>>4)-1)|0x10000000;
   s->cursor=p;
  }
 }
}
