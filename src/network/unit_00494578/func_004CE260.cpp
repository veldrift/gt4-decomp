/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned int u32;
struct Word { u32 word; } __attribute__((packed));
struct Header { char pad[0x2c]; Word value; };
struct Buf { char pad[8]; char *data; };
struct Obj { char pad[4]; void *list; char pad2[0x50-8]; u32 size; int start,state,stride; char pad3[4]; int count; char pad4[12]; int empty; void *vt; u32 value; int index; };
extern char D_00689478[];
extern "C" void *func_004CB618(Obj *,int,void *) throw();
extern "C" int func_004CA278(Header **) throw();
extern "C" Buf *func_004CA820(void *,u32) throw();
extern "C" void func_004CA938(void *,Buf *) throw();
extern "C" int func_004CE478(Obj *,int);
extern "C" void func_004CE508(Obj *,int,int);
extern "C" void func_004CE260(Obj *p,int a1,void *a2,Header **arg3) {
 func_004CB618(p,a1,a2);
 p->vt=D_00689478;
 p->value=(*arg3)->value.word;
 int n=func_004CA278(arg3);
 p->index=n;
 if(n>=0) { p->state=1; p->start+=p->stride*n; }
 int f=func_004CE478(p,1);
 if(f>0) func_004CE508(p,1,f&0xf7ffffff);
 int block=0;
 p->empty=0;
 u32 off=0;
 int i=0;
 while(i<p->count) {
  Buf *b=func_004CA820(p->list,p->start+block);
  if(!b) { i+=p->size>>2; } else {
   while(i<p->count && off<p->size) {
    u32 v=((Word *)(b->data+off))->word;
    off+=4;
    if(!(v&0x0fffffff)) p->empty++;
    i++;
   }
   func_004CA938(p->list,b);
  }
  off=0;
  block++;
 }
}
