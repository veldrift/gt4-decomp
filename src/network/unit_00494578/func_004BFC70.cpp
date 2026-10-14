/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
struct Ent { char *data; int pad4; u16 flag,a,b; char padE[2]; };
struct Obj { int x0; int *status; char pad8[0x1c]; char *table; };
extern "C" void func_004BD230(Obj *,u16) throw();
extern "C" int func_004BEC88(Obj *,void *) throw();
static inline char *record(Ent *e, Ent *f, int kind, int expected, u16 i) {
 int off=i*20;
 if(kind==expected) { int n=e->a; char *data=e->data+off; return data+n*6+6; }
 else { int n=f->a+f->b; char *data=f->data+off; return data+n*6+6; }
}
static inline void resetAll(char *table,u16 id,u8 d) {
 Ent *e=(Ent *)((unsigned int)table+((id&255)*16+0x40));
 unsigned int n=(u16)(e->a+1);
 u16 i=1;
 if(i<n) {
 int kind=id&0xff00;
 int expected=0x200;
 u8 a=0,b=0,c=0;
 do {
  Ent *e=(Ent *)((unsigned int)table+((id&255)*16+0x40));
  Ent *f=(Ent *)((unsigned int)table+((id&255)*16+0x50));
  char *p=record(e,f,kind,expected,i);
  p[14]=a; p[15]=b; p[16]=c; p[17]=d;
 i++;
 } while(i<n);
 }
}
extern "C" int func_004BFC70(Obj *o,u16 id) {
 char *table=o->table;
 if(*o->status==0) func_004BEC88(o,(void *)1);
 if((id&0xff00)==0x200) {
  resetAll(table,id,0);
 } else func_004BD230(o,id);
 return 0;
}
