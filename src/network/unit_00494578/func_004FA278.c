/* compiler: ee-gcc2.96-nogcse */
typedef struct A A;
struct A {int w[21];};
typedef struct B B;
struct B {int w[57];};
typedef struct Ent Ent;
struct Ent {int id,kind,type,pad;};
typedef struct List List;
struct List {Ent a[32]; int n;};
typedef struct Handle Handle;
struct Handle {char pad[28];void *p;};
typedef struct Obj Obj;
struct Obj {char pad0[0xcc0];int cc0,cc4,cc8,ccc,cd0,cd4;List list;char pad1[0x88]; A a;int active;char pad2[0x1284];int flags[16];B b[16];int size;char pad3[0x40];char data[4];};
int func_004F68C8(Obj *);
int func_004F9E60(Obj *,int);
int func_00515998(Handle **,int);
void func_00576100(Obj *);
void func_00576140(Obj *);
void *func_005A4724(void *,const void *,unsigned);
void func_004FA278(Obj *o) {
 Handle *h;
 if(o->active) {
  int kind,i,n; List *list;
  if(func_004F68C8(o)) {
   h=0;
   if(func_00515998(&h,o->cc0)==0 && h) {
    void *p=h->p;
    if(p) *(A *)p=o->a;
   }
  }
  list=&o->list;
  i=0;
  kind=func_004F9E60(o,o->cc4);
  n=list->n;
  if(n>0) {
  Ent *e=list->a;
  do {
   int type=e->type;
   int id=e->id;
   if(type!=o->ccc && kind==e->kind) {
    h=0;
    if(func_00515998(&h,id)==0 && h && h->p) {
     func_00576100(o);
     if(type==o->cd0) {
      B *dst=(B *)h->p;
      B *src=(B *)((char *)o+kind*0xe4+0x2280);
      if(o->flags[kind]==0) *dst=*src;
     } else if(type==o->cd4)func_005A4724(h->p,o->data,o->size);
     func_00576140(o);
    }
   }
   n=list->n;
   i++; e++;
  } while(i<n);
  }
 }
}
