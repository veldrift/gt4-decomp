/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int state, status, mode; char b10[16]; int info; char b24[4]; int ready; char data[20]; };
struct Out { int len1; char src2[16]; int len0; char src1[16]; };
struct Port { int id; State state; int pending; Out out; };
struct Flag { int v; };
extern volatile Flag D_0064C714;
extern char D_0086F940[];
static inline int active(volatile Flag *const p) { return p->v; }
extern Port D_0086FC80[];
extern "C" void func_00551568(State *) throw();
extern "C" void func_00551D08();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_0058EF08(int, void *);
extern "C" int func_0058EFE0(int, void *);
extern "C" unsigned char func_0058F0B0(int);
extern "C" int func_0058F5B8(int, void *);
extern "C" int func_0058F638(int, int, void *, int, void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005ADB30(int,int);
extern "C" int func_005ADB90();
extern "C" void func_00551580() {
 if (active(&D_0064C714)) {
  func_00576788(D_0086F940);
  int th=func_005ADB90();
  int prev=func_005ADB30(th,1);
  for (int i=0; i<2; ++i) {
   Port *p=&D_0086FC80[i];
   State *s=&p->state;
   Out *o=&p->out;
   int connected=func_0058F0B0(p->id);
   int state=s->state;
   if (connected==1) {
    switch(state) {
    case 0:
     s->info=func_0058EFE0(p->id,s->b24);
     s->mode=func_0058F5B8(p->id,s->b10);
     s->state=1;
     s->status=0;
     break;
    default: s->status=3; break;
    case 1: s->status=0; s->state=2; break;
    }
    s->ready=func_0058EF08(p->id,s->data);
    if (p->pending && func_0058F638(p->id,o->len1,o->src2,o->len0,o->src1)==1) {
     if (--p->pending) func_005A48D8(o->src1,0,o->len0);
    }
   } else {
    func_00551568(s);
    p->pending=0;
   }
  }
  func_005ADB30(th,prev);
  func_005767C0(D_0086F940);
  func_00551D08();
 }
}
