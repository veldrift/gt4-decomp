/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { int count,read,write; char *data; int size; char pad[8]; char mutex[0x34]; };
struct Obj { char pad[0x80]; unsigned size; void *entry; int a88,a8c; char pad90[0x100]; char *base,*cur; int a198,mode,loop,flags,memory; char pad1ac[0x144]; char sem1[0x60]; char sem2[0x30]; Ring ring; int task; int a3d4; void *stack; int a3dc,run,a3e4; void *stream; int a3ec,a3f0,a3f4,a3f8; };
struct Block { char b[0xa000]; };
struct Task { void (*fn)(); Obj *arg; char pad[24]; };
struct Stack { void *base; int size; char pad[8]; };
extern int D_00654D8C,D_00654D88,D_0064C4B8,D_0064C4B0,D_0064C4AC,D_0064C4BC,D_0064C4B4;
extern "C" {
int func_0054E200(Obj*) throw(); void func_0054E340(Obj*) throw();
void func_0054F388(int,void*,unsigned,void*); void func_0054F648();
void func_0054F7E0(void*,int,int,int,int); void func_0054F9A8(void*);
int func_0054FBB8(void*,void*); int func_0054FCF8(void*); void func_0054FDA8(void*);
char *func_00563408(int);
void func_00574E78(void*); void func_00574EB0(void*); void func_00574EE8(void*);
void func_00576788(void*); void func_005767C0(void*);
void *func_00578610(int); int func_005788B8(int); void func_00578908(int);
int func_00578968(Task*,Stack*,void*); void func_00578AF0(int); void func_00578B10(int);
int func_00578B50(unsigned,int); void func_0057B3B0(Ring*,int);
void *func_005A4724(void*,const void*,unsigned);
int func_005ADB90(); void func_005ADBC0(); int func_005ADCC0(int); int func_005ADCE0(int);
void func_0054DB98();
}
struct Guard {void *p; Guard(void *q):p(q){func_00576788(q);} ~Guard(){func_005767C0(p);} };
static inline void clear(Ring *r) {Guard guard(r->mutex);r->count=0;r->read=0;r->write=0;}
static inline void consume(Ring *r,char *buf) {Guard guard(r->mutex);func_005A4724(buf,r->data+r->read*r->size,r->size);func_0057B3B0(r,1);}
static inline void initTask(Task *t,Obj *p) {t->fn=func_0054DB98;t->arg=p;}
static inline void initStack(Stack *s,void *base) {s->base=base;s->size=8192;}
extern "C" void func_0054E3D8(Obj *p) {
 if(!func_0054E200(p)) return;
 int memory;
 int reading=1;
 int flags=p->flags&15;
 memory=p->memory;
 switch(p->mode){case 0:break;case 2:flags|=32;case 1:flags|=64;}
 if(!p->loop) flags|=16;
 func_005ADCE0(D_00654D8C);
 func_0054F7E0(p->stream,p->a88,p->a8c,p->a3f8,p->a3ec);
 int stopped=D_00654D88==1;
 if(stopped) D_00654D88=0;
 func_005ADCC0(D_00654D8C);
 D_0064C4B8=0;D_0064C4B0=0;
 if(!stopped) {
  if(memory) p->cur=p->base;
  else {
   func_0054F388(flags,p->entry,(p->size+2047)>>11,p);
   clear(&p->ring);
   func_00574E78(p->sem1);func_00574E78(p->sem2);
   Task task; Stack stack;
   initTask(&task,p);initStack(&stack,p->stack);
   int t=func_00578968(&task,&stack,func_00578610(func_00578B50(3,0)));
   p->run=1;p->task=t;func_005788B8(t);
  }
  char *buf=func_00563408(0);
  func_005ADCE0(D_0064C4AC);
  for(;;) {
   func_0054E340(p);
   if(memory) {*(Block*)buf=*(Block*)p->cur;p->cur+=0xa000;}
   else if(reading) {
    D_0064C4BC=1;func_00574EB0(p->sem1);
    consume(&p->ring,buf);
    func_00574EE8(p->sem2);D_0064C4BC=0;
   } else func_00578B10(1000);
   for(int i=0;i<8;i++) {
    int result;
    do {
     result=func_0054FBB8(p->stream,buf+i*0x1400);
     switch(result) {
     case 0:break;
     case 1:goto done;
     case 2:
      if(memory) {p->cur=p->base;goto next;}
      if(p->loop==1) {
       i=7;func_005ADCE0(D_00654D8C);result=0;reading=0;D_00654D88=1;func_005ADCC0(D_00654D8C);
      } else result=0;
      break;
     case 3:D_0064C4B4=func_005ADB90();func_005ADBC0();D_0064C4B4=-1;break;
     }
    } while(result);
   }
   next:
   if(!D_0064C4B8&&!D_0064C4B0) if(func_0054FCF8(p->stream)) D_0064C4B0=1;
  }
  done:
  D_0064C4B0=0;
  if(!memory) {
   p->run=0;func_00574EE8(p->sem2);func_00578908(p->task);func_00578AF0(p->task);p->task=0;func_0054F648();
  }
 }
 func_0054FDA8(p->stream);func_005ADCE0(D_00654D8C);func_0054F9A8(p->stream);func_005ADCC0(D_00654D8C);
}
