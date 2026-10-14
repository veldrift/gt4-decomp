/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, pad; void (*fn)(void *, int); };
struct Base { Entry *vt; };
struct Obj { char pad[0x4c]; Entry *vt; };
struct Manager { char pad[0x678]; int m678; Obj *m67c; char p680[0x50]; int a,b,c,d; };
struct Info { int p0,p4; long long key; int a,b,c; int *data; int x; };
struct Self { char pad[0x14]; int mode; Obj *obj; Base *base; Manager *mgr; Obj *aux; int *data; int a,b; };
struct Vec { int x,a,b,c; };
extern "C" {
void func_001CB850(void *);
int func_001CBFE0(void *);
int func_001CDA10(void *);
int func_001D11D0(void *, int);
int func_001D1228(void *, int);
void func_001D16E0(void *, int);
int func_001D1950(void *, void *, const char *);
void func_001D2470(void *, void *);
void func_001D2518(void *, int);
void func_001D2AA8(void *, int);
Info *func_001D3A60();
int func_00448368(long long);
void *exception__structor_0(int);
extern char D_006911A0[];
extern Entry D_006612F8[], D_006611F0[], D_00660FC0[], D_00660EA8[], D_00661860[], D_00661758[], D_00661B70[], D_00661A70[];
extern int D_00621C98;
}
static inline void replace(Base **slot, Base *n) {
 Base *o=*slot;
 if(o) { Entry *e=o->vt+1; e->fn((char*)o+e->delta,3); }
 *slot=n;
}
static inline void replace(Obj **slot, Obj *n) {
 Obj *o=*slot;
 if(o) { Entry *e=o->vt+1; e->fn((char*)o+e->delta,3); }
 *slot=n;
}
static inline void invoke(Obj *o,int *data) {
 Entry *e=o->vt+2; e->fn((char*)o+e->delta,(int)data);
}
static inline void vecinit(Vec *p) { p->a=0; p->b=0; p->c=0; }
static inline Obj *large(int size,Entry *vt) {
 Obj *o=(Obj*)exception__structor_0(size);
 func_001CBFE0(o);
 o->vt=D_006611F0;
 vecinit((Vec*)((char*)o+0x50));
 o->vt=vt;
 *(int*)((char*)o+0x60)=0;
 return o;
}
extern "C" void func_0017C348(Self *self,int mode,int arg) {
 char stack[0x40];
 self->mode=mode;
 Base **bs;
 if(mode==2) {
  bs=&self->base;
  func_001CB850(stack);
  Base *n=(Base*)exception__structor_0(0x48);
  func_001D1950(n,stack,D_006911A0);
  replace(bs,n);
 } else {
  bs=&self->base;
  Base *n=(Base*)exception__structor_0(8);
  func_001D16E0(n,arg);
  replace(bs,n);
 }
 Manager **ms=&self->mgr;
 Manager *m=(Manager*)exception__structor_0(0x6e4);
 func_001D2470(m,*bs);
 if(*ms) func_001D2518(*ms,3);
 *ms=m;
 self->data=func_001D3A60()->data;
 switch(self->mode) {
 case 0: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x50); func_001CDA10(n);
  replace(slot,n); invoke(n,self->data); break;
 }
 case 16: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x50); func_001CDA10(n); n->vt=D_006612F8;
  replace(slot,n); break;
 }
 case 6: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x150); func_001CBFE0(n);
  n->vt=D_006611F0; vecinit((Vec*)((char*)n+0x50));
  n->vt=D_00660FC0; *(int*)((char*)n+0x60)=0;
  replace(slot,n); invoke(n,self->data); func_001D2AA8(*ms,2); break;
 }
 case 7: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x150); func_001CBFE0(n);
  n->vt=D_006611F0; vecinit((Vec*)((char*)n+0x50));
  n->vt=D_00660EA8; *(int*)((char*)n+0x60)=0;
  replace(slot,n); invoke(n,self->data); func_001D2AA8(*ms,2); break;
 }
 case 1: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x50); func_001CDA10(n);
  replace(slot,n); break;
 }
 case 5: {
  Info *i=func_001D3A60();
  Manager *target=*ms; target->a=func_00448368(i->key);
  (*ms)->b=i->a; (*ms)->c=i->b; (*ms)->d=i->c;
  func_001D2AA8(*ms,4);
  self->a=(int)i->data; self->b=0; self->data=&self->a; break;
 }
 case 2: case 4:
  func_001D2AA8(*ms,2);
  self->a=(int)func_001D3A60()->data; self->b=D_00621C98; self->data=&self->a; break;
 case 10: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x150); func_001CBFE0(n);
  n->vt=D_006611F0; vecinit((Vec*)((char*)n+0x50));
  n->vt=D_00661860; *(int*)((char*)n+0x60)=0;
  replace(slot,n); invoke(n,self->data); break;
 }
 case 8: func_001D2AA8(*ms,6); break;
 case 11: {
  Obj **slot=&self->obj;
  Obj *n=(Obj*)exception__structor_0(0x160); func_001CBFE0(n);
  n->vt=D_006611F0; vecinit((Vec*)((char*)n+0x50));
  n->vt=D_00661758; *(int*)((char*)n+0x60)=0; vecinit((Vec*)((char*)n+0x150));
  replace(slot,n); invoke(n,self->data); break;
 }
 case 9: func_001D2AA8(*ms,7); break;
 case 12: func_001D2AA8(*ms,8); break;
 case 13: { Manager *target=*ms; target->m678=func_001D3A60()->x; func_001D2AA8(*ms,8); break; }
 case 14: func_001D2AA8(*ms,8); break;
 }
 switch(self->mode) {
 case 9: case 12: {
  Obj **slot=&self->aux;
  Obj *n=(Obj*)exception__structor_0(0x58); func_001CBFE0(n);
  *(int*)((char*)n+0x50)=0; n->vt=D_00661B70; func_001D11D0(n,0);
  replace(slot,n); invoke(n,0); (*ms)->m67c=*slot; break;
 }
 case 3: case 4: case 14: {
  Obj **slot=&self->aux;
  Obj *n=(Obj*)exception__structor_0(0x58); func_001CBFE0(n);
  *(int*)((char*)n+0x50)=0; n->vt=D_00661A70; func_001D1228(n,0);
  replace(slot,n); invoke(n,0); (*ms)->m67c=*slot; break;
 }
 }
}
