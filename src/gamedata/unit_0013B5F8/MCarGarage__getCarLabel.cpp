/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; char pad[12]; };
struct Str {char *p; char pad[12];};
struct Rep {int len,cap,ref,sel;};
struct TI {const char *name;};
extern Rep D_00659FA8;
extern char D_0068EE98[];
extern "C" {
void func_0013BDC0(void *,void *) throw();
void func_0013BD68(void *,int) throw();
void *func_00147D80(void *);
void *func_00441248(void *);
const char *func_00146598(void *);
void func_002EFBF0(void *);
int func_00448788(void *,int *,int *);
const char *func_00448DF0(int);
int func_0057F238(const char *,const char *) throw();
int func_0057F260(const char *) throw();
char *func_005C2560(Rep *);
void *func_005C2630(Str *,int,int,const char *,int);
void func_00314B20(void *,Str *);
void *func_002EEEB0(void *,void *,void *);
void func_00309378(void *,int);
void func_00312318(void *,int);
TI *func_005C11A8();
void func_00326798(void *,int,int,const char *);
int func_004478F8(void *,int *,int);
void func_003285A8(void *);
void func_003285F8(void *);
void func_002ED5C0(void *,int);
}
static inline void release(Str *s) {
 Rep *r=(Rep*)(s->p-16);
 if(--r->ref==0) {int size=r->cap+16;func_00326798(r,size,4,func_005C11A8()->name);}
}
static inline void assign(H *dst,H *src) {
 if(dst!=src) {void *p=src->p; if(p)func_003285A8(p); if(dst->p)func_003285F8(dst->p);dst->p=p;}
}
extern "C" void MCarGarage__getCarLabel(H *out,H *src) {
 struct Frame {H h;H sym;Str a;Str b;} f;
 func_0013BDC0(&f.h,src);
 const char *text=func_00146598(f.h.p);
 if(text) {
 Rep *r=&D_00659FA8; Str *ps=&f.a; char *d;
 if(r->sel)d=func_005C2560(r);else {d=(char*)(r+1);r->ref++;}
 ps->p=d;
 func_005C2630(ps,0,-1,text,func_0057F260(text));
 H *sym=&f.sym;
 func_00314B20(sym,ps);
 assign(out,sym);func_00312318(sym,2);release(ps);
 }else{
 const char *s=D_0068EE98;
 Rep *r=&D_00659FA8; Str *ps=&f.b;char *d;
 if(r->sel)d=func_005C2560(r);else {d=(char*)(r+1);r->ref++;}
 ps->p=d;
 func_005C2630(ps,0,-1,s,func_0057F260(s));
 H *sym=&f.sym;
 func_00314B20(sym,ps);
 assign(out,sym);func_00312318(sym,2);release(ps);
 }
 func_0013BD68(&f.h,2);
}
