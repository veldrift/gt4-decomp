/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
struct Child {char pad[0xb4]; int axis,flag;};
struct Obj {int v,axis; char pad[16]; float length,width; void *parent; Child *dec,*inc,*base,*pinch;};
extern Rep D_00659FA8;
extern char D_0069CB10[],D_0069CB18[],D_0069CB20[],D_0069CB28[];
extern "C" void mTextFace__virtual_67();
extern "C" void *func_0030BB18(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,int,int,const char *,int);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void *func_00204D88(void *,void *);
extern "C" void func_00204D30(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void func_00266438(void *,int);
extern "C" void func_002D2020(void *,void *) throw();
extern "C" void func_002D1FF8(Obj *);
extern "C" void mWidget__getWindowSize(void *,float *,float *);
extern "C" void *func_002D05C0(void *,void *) throw();
extern "C" void func_002D0568(void *,int) throw();
extern "C" void *func_002D0BD0(void *,void *) throw();
extern "C" void func_002D0B78(void *,int) throw();
extern "C" void *func_002D1110(void *,void *) throw();
extern "C" void func_002D10B8(void *,int) throw();
extern char D_0069CAB8[],D_0069CAC0[],D_0069CAC8[],D_0069CAD0[];
extern "C" void func_002D1B78(Obj *o,int arg,void *parent) {
 float xy[2]; int handle[4],name[4]; Str a,b,c,d;
 func_002D1FF8(o);
 if(parent) {
 float *y=&xy[1];
 o->parent=parent;
 mWidget__getWindowSize(parent,xy,y);
 float size=xy[1];if(!o->axis) size=xy[0];
 o->length=size;
 int *ph=handle;
 func_0030BB18(ph);
 int *pn=name;
 {
 const char *src=D_0069CAB8;
 Rep *r=&D_00659FA8;
 Str *ps=&a;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1);r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o->parent,ph,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(ph[0],0)) {
 func_002D05C0(pn,ph);o->dec=(Child *)pn[0];func_002D0568(pn,2);
 mWidget__getWindowSize(o->dec,xy,y);
 int axis=o->axis;float width=xy[0];if(!axis)width=xy[1];
 Child *c=o->dec;o->width=width;c->axis=axis;c->flag=1;
 } else o->width=0;
 }
 {
 const char *src=D_0069CAC0;
 Rep *r=&D_00659FA8;
 Str *ps=&b;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1);r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o->parent,ph,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(ph[0],0)) {
 func_002D05C0(pn,ph);o->inc=(Child *)pn[0];func_002D0568(pn,2);
 Child *c=o->inc;int axis=o->axis;c->flag=0;c->axis=axis;
 }
 }
 {
 const char *src=D_0069CAC8;
 Rep *r=&D_00659FA8;
 Str *ps=&c;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1);r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o->parent,ph,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(ph[0],0)) {
 func_002D0BD0(pn,ph);o->base=(Child *)pn[0];func_002D0B78(pn,2);
 o->base->axis=o->axis;
 }
 }
 {
 const char *src=D_0069CAD0;
 Rep *r=&D_00659FA8;
 Str *ps=&d;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1);r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o->parent,ph,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(ph[0],0)) {
 func_002D1110(pn,ph);o->pinch=(Child *)pn[0];func_002D10B8(pn,2);
 o->pinch->axis=o->axis;
 }
 }
 func_00309378(ph,2);
 }
}
