/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int focus, state, x, y, w, h; };
struct Obj { char pad[0x254]; int limit, period, threshold; char pad260[0x18]; int reset, active, ready, recognized, count, ticks, hits; char pad294[0x18]; Blob data; char pad2c4[0x18]; void *widget; };
struct Handle { void *p; char pad[12]; };
struct Str { char *p; char pad[12]; };
struct Rep { int len, cap, ref, sel; };
struct Info { const char *name; };
union Work { Blob b; struct { Handle h; Str s; } t; };
extern Rep D_00659FA8;
extern char D_00693C90[], D_00693CA0[], D_00693CB8[];
extern "C" {
void func_001C2E90(Blob *, Obj *) throw();
void func_002319A0(void *, void *);
void func_00239F08(void *, int);
void func_0023A538(void *, void *, int, void *, void *);
void mWidget__setActive(void *, int);
void func_002ED5C0(void *, int);
void func_002EFBF0(void *);
void func_002EFC48(void *, int);
Handle *HArray__operator_index(void *, int);
void func_002F7B68(void *, int);
void func_002F9360(void *, float);
void func_00326798(void *, int, int, const char *);
void func_003285A8(void *);
void func_003285F8(void *);
void func_00576090(void *);
void func_005760A8(void *, int);
void func_00576100(void *);
void func_00576140(void *);
int func_0057F260(const char *) throw();
Info *func_005C11A8();
char *func_005C2560(Rep *);
void *func_005C2630(void *, unsigned, unsigned, const char *, unsigned);
}
#define MAKESTR(ps,src) { Rep *r = &D_00659FA8; char *d; if (r->sel) d=func_005C2560(r); else { d=(char *)(r+1); r->ref++; } (ps)->p=d; func_005C2630(ps,0,-1,src,func_0057F260(src)); }
#define FREESTR(ps) { Rep *r=(Rep *)((ps)->p-16); if (--r->ref==0) { int cap=r->cap+16; func_00326798(r,cap,4,func_005C11A8()->name); } }
#define SETVAL(n,field) { dst=HArray__operator_index(ph,n); func_002F9360(tmp,(float)o->data.field); if(dst!=tmp) { value=tmp->p; if(value) func_003285A8(value); if(dst->p) func_003285F8(dst->p); dst->p=value; } func_002F7B68(tmp,2); }
extern "C" void mGTShirtPS2__virtual_51(Obj *o, void *a, int b) {
 char guard[16]; Work u,v;
 int reset=1;
 func_00576090(guard);
 int oldFocus=o->data.focus, oldState=o->data.state;
 if(o->ready) {
  func_00576100(guard); reset=o->reset; o->reset=0; func_00576140(guard);
  Work *pu=&u; func_001C2E90(&pu->b,o); Work *pv=&v;
  pv->b=pu->b; o->data=pv->b;
  if(o->data.focus) {
   o->count++;
   int state=o->data.state;
   if(oldState!=state && state==o->active) o->hits++;
   o->ticks++;
   int oldRecognized=o->recognized;
   o->recognized=o->hits>=o->threshold;
   if(o->ticks>=o->period) { int flag=0; if(o->recognized || (o->count>=o->limit && state==0)) flag=1; o->active=flag; o->ticks=0; }
   if(!oldFocus) {
    if(o->widget) mWidget__setActive(o->widget,1);
    const char *src=D_00693C90; Str *ps=&u.t.s;
    MAKESTR(ps,src);
    func_002EFBF0(&pv->t.h);
    func_0023A538(&pu->t.h,a,b,ps,&pv->t.h);
    func_002319A0(a,&pu->t.h); func_00239F08(&pu->t.h,2); func_002ED5C0(&pv->t.h,2); FREESTR(ps);
   }
   if(oldRecognized!=o->recognized) {
    Handle *ph=&pu->t.h;
    func_002EFC48(ph,4);
    Handle *tmp;
    Handle *dst; void *value;
    { dst=HArray__operator_index(ph,0); tmp=(Handle *)&u.t.s; func_002F9360(tmp,(float)o->data.x); if(dst!=tmp) { value=tmp->p; if(value) func_003285A8(value); if(dst->p) func_003285F8(dst->p); dst->p=value; } func_002F7B68(tmp,2); } SETVAL(1,y); SETVAL(2,w); SETVAL(3,h);
    const char *src=D_00693CA0; Str *ps=(Str *)&pv->t.h; MAKESTR(ps,src);
    func_0023A538(tmp,a,b,ps,ph); func_002319A0(a,tmp); func_00239F08(tmp,2); FREESTR(ps); func_002ED5C0(ph,2);
   }
  } else {
   if(oldFocus) {
   if(o->widget) mWidget__setActive(o->widget,0);
   const char *src=D_00693CB8; Str *ps=&u.t.s; MAKESTR(ps,src);
   func_002EFBF0(&pv->t.h); func_0023A538(&pu->t.h,a,b,ps,&pv->t.h); func_002319A0(a,&pu->t.h); func_00239F08(&pu->t.h,2); func_002ED5C0(&pv->t.h,2); FREESTR(ps);
   }
   reset=1;
  }
 }
 if(reset) { o->active=1; o->recognized=0; o->count=0; o->ticks=0; o->hits=0; }
 func_005760A8(guard,2);
}
