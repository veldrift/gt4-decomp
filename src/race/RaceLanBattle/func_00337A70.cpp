/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Raw32 { char b[32]; };
struct Entry {
 int a,b,flags; Raw32 input; char pad2[12]; int buttons; unsigned short x,y; int z; int state; char pad3[0x80-0x48];
};
struct Packet { Entry entries[16]; int tail; };
struct Queue { int a,index,c; Packet packets[4]; };
struct Net { char pad[0x67D8]; Queue queue; char pad2[0x87F8-0x67D8-sizeof(Queue)]; int lock; };
struct VE { short delta,idx; int (*fn)(void *); };
struct Control { Raw32 *data; int buttons; char pad[16]; int x,z,y; };
struct Item { char input[0x170]; Control control; char pad[0x214-0x170-sizeof(Control)]; };
struct Block { char pad[0x58]; int start,end; char pad2[0x84-0x60]; Item items[6]; void advance() { end=start+4; } };
struct Self {
 char p0[0x64]; char *vt;
 char p1[0xCE0-0x68]; int mode;
 char p2[0xE448-0xCE4]; int player; int fE44C; int count;
 char p3[0xE468-0xE454]; int changed; int fE46C; int all; float value; int number; int bit; Net *net;
 int fE484; Block block; char p4[0xF370-0xE488-sizeof(Block)]; int flags; int fF374; int pause; int fF37C; int pauseCount; int count2; int owner; int timer;
};
extern "C" void func_00335DD8(void *,int) throw();
extern "C" void func_0043A138(Control *);
extern "C" void func_00427028(void *);
extern "C" void RaceBasic__pauseStart(void *,int);
extern "C" void RaceBasic__pauseEnd(void *);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_005F3268(void *,int);
extern "C" int D_006494B4;
struct Lock {
 void *p;
 Lock(void *v) { p=v; func_00576100(p); }
 ~Lock() { func_00576140(p); }
};
inline Packet take(Net *n) {
 Queue *q=&n->queue;
 Lock guard(&n->lock);
 Packet *src=q->packets+q->index;
 Packet result=*src;
 func_005F3268(q,1);
 return result;
}
extern "C" void func_00337A70(Self *self) {
 int oldPause=self->pause;
 int oldCount=self->pauseCount;
 int oldCount2=self->count2;
 int newPause=0;
 int newCount=0;
 int newCount2=0;
 int pressed=0;
 int owner=-1;
 int player=self->player;
 VE *v=(VE*)(self->vt+0x310);
 int active=v->fn((char*)self+v->delta);
 int all=1;
 Packet packet=take(self->net);
 int i=0;
 if (i<self->count) {
 Block *block=&self->block;
 char *item=(char*)self;
 Entry *e=packet.entries;
 do {
  Control *c=(Control*)(item+0xE67C);
  void *input=item+0xE50C;
  func_00335DD8(input,e->flags&3);
  func_0043A138(c);
  *c->data=e->input;
  int state=e->state;
  if (((state>>15)^1)&1) all=0;
  int buttons=c->buttons | e->buttons;
  int x=c->x | e->x;
  int y=c->y | e->y;
  int z=c->z | e->z;
  c->buttons=buttons;
  c->x=x;
  c->y=y;
  c->z=z;
  if(i==active) {
   self->value=(float)((unsigned int)state>>16)/100.0f;
   self->number=((unsigned int)state>>1)&0x3FFF;
   self->bit=state&1;
  }
  unsigned int flags=e->flags;
  if(flags&4) pressed++;
  if(flags&8) {
   if(oldCount==0) {
    owner=i; newCount=1;
    if(owner!=player) self->flags &= ~8;
   } else { owner=self->owner; newCount=oldCount+1; }
  }
  if(flags&16) {
   if(oldCount2==0) newCount2=1; else newCount2=oldCount2+1;
  }
  if(flags&32) {
   self->mode=(flags&0x3C0)>>6;
   if(self->fF37C==0) {
    self->fF37C=1;
    block->advance();
   }
  }
  func_00427028(input);
  i++; item+=0x214; e++;
 } while(i<self->count);
 }
 self->all=all;
 self->pauseCount=newCount;
 self->count2=newCount2;
 self->owner=owner;
 if(pressed) { if(pressed!=D_006494B4) self->changed=1; newPause=1; }
 if(oldPause!=newPause) {
  self->timer=0;
  self->pause=newPause;
  if(newPause==0) RaceBasic__pauseStart(self,0); else RaceBasic__pauseEnd(self);
 }
}
