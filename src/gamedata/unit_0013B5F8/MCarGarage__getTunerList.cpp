/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; char pad[12]; };
struct Str {char *p; char pad[12];};
struct Rep {int len,cap,ref,sel;};
struct TI {const char *name;};
extern Rep D_00659FA8;
extern char D_0068EEB0[];
extern "C" {
void func_0013BDC0(void *,void *) throw();
void func_0013BD68(void *,int) throw();
void *func_00147D80(void *);
void *func_00441248(void *);
void *func_004454C0(void *);
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
extern "C" void MCarGarage__getTunerList(H *out,H *src) {
 struct Frame { H h; int a,b; char pad[8]; H r; H sym; Str str; int arr[10]; char pad2[8]; H sym2; Str str2; } f;
 func_0013BDC0(&f.h,src);
 void *obj=func_004454C0(func_00441248(func_00147D80(f.h.p)));
 func_0013BD68(&f.h,2);
 func_002EFBF0(&f.h);
 func_00448788(obj,&f.a,&f.b);
 const char *text=func_00448DF0(f.b);
 if(func_0057F238(text,D_0068EEB0)!=0) {
 H *pr=&f.r;
 void *arr=f.h.p;
 Str *ps=&f.str;
 Rep *r=&D_00659FA8; char *d;
 if(r->sel) d=func_005C2560(r); else {d=(char*)(r+1);r->ref++;}
 ps->p=d;
 func_005C2630(ps,0,-1,text,func_0057F260(text));
 H *sym=&f.sym;
 func_00314B20(sym,ps);
 func_002EEEB0(pr,arr,sym);
 func_00309378(pr,2);func_00312318(sym,2);release(ps);
 }
 int n=func_004478F8(obj,f.arr,10);
 if(n>0) {
 Str *ps=&f.str2;
 Rep *r=&D_00659FA8;
 int *cur=f.arr;
 int count=n;
 do {
 H *pr=&f.r;
 const char *s=func_00448DF0(*cur++);
 void *arr=f.h.p;
 char *d;
 if(r->sel)d=func_005C2560(r);else {d=(char*)(r+1);r->ref++;}
 ps->p=d;
 func_005C2630(ps,0,-1,s,func_0057F260(s));
 Str *q=&f.str2;
 H *sym=&f.sym2;
 func_00314B20(sym,q);
 func_002EEEB0(pr,arr,sym);
 func_00309378(pr,2);func_00312318(sym,2);release(q);
 }while(--count!=0);
 }
 if(out != &f.h) {
 void *p=f.h.p;
 if(p)func_003285A8(p);
 if(out->p)func_003285F8(out->p);
 out->p=p;
 }
 func_002ED5C0(&f.h,2);
}
