struct Node { char pad[12]; int state, a, b, pad18, f1c, active; };
struct Obj { Node *slots[64]; int f100; unsigned selected; char pad108[0x14c-0x108]; int busy; };
struct Result { int pad[2]; int a; int padC; int b; };
struct Event { int code, data; };
struct Global { char pad[0x108]; int f108; char pad10c[0x10]; int mode; void (*cb)(Event *); int data; };
extern Global *D_0064B4B4;
extern "C" Node *func_00535C88(Obj *, unsigned);
extern "C" Result *func_0051B8A8(Obj *, unsigned);
extern "C" void func_005310D0(Obj *, unsigned);
extern "C" int func_00518B58(Obj *, int) throw();
extern "C" void func_00518E68(Obj *, int) throw();
extern "C" int func_00534990(Obj *, int);
extern "C" void func_0051B018(Obj *, unsigned, int, int);
extern "C" void func_00519BA0(Obj *o) {
 int count=0;
 unsigned selected=256;
 Event ev;
 if (!o) return;
 if (o->busy) return;
 if ((unsigned)(D_0064B4B4->mode-1)>=2) return;
 for (unsigned i=0;i<64;i++) {
  Node *n=func_00535C88(o,i);
  if (n && n->active) {
   int state=n->state;
   if (state==0) return;
   if (state==5) return;
   if (state==3) { if ((selected ^ 256)==0) selected=i; }
   if ((state ^ 4)==0) count++;
  }
 }
 if (count) return;
 if (selected!=o->selected) return;
 Result *r=func_0051B8A8(o,selected);
 if (!r) {
  o->slots[selected]->state=2;
  func_005310D0(o,-1);
  if (D_0064B4B4->cb) {
   ev.data=D_0064B4B4->data; ev.code=22;
   D_0064B4B4->cb(&ev);
   D_0064B4B4->cb=0;
   D_0064B4B4->data=0;
   return;
  }
 }
 o->slots[selected]->state=5;
 o->slots[selected]->f1c=1;
 func_00518B58(o,selected);
 func_005310D0(o,-1);
 r->a=0; r->b=0;
 D_0064B4B4->f108=1;
 func_00534990(o,1);
 func_00518E68(o,selected);
 if (D_0064B4B4->cb) {
  ev.data=D_0064B4B4->data; ev.code=0;
  D_0064B4B4->cb(&ev);
  D_0064B4B4->cb=0;
  D_0064B4B4->data=0;
 }
 for (unsigned i=0;i<64;i++) {
  Node *n=func_00535C88(o,i);
  if(n && n->active && n->state==3 && selected!=i)
   func_0051B018(o,i,n->a,n->b);
 }
}
