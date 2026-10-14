/* compiler: ee-gcc2.96-no-strict-aliasing */
inline void *operator new(unsigned int, void *p) { return p; }
struct Alloc {};
struct IV { int unused, a,b,c; IV(const Alloc &a0=Alloc()) { a=0;b=0;c=0; } };
struct V3 { float x,y,z; void set(float a,float b,float c) {x=a;y=b;z=c;} };
struct V4 { float x,y,z,w; ~V4() {} V4(float a=0,float b=0,float c=0,float d=0):x(a),y(b),z(c),w(d) {} void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;} };
struct VA { V4 v[100]; };
struct M3 {float v[9]; void set(float z,float o) {v[0]=o;v[3]=z;v[6]=z;v[1]=z;v[4]=o;v[7]=z;v[2]=z;v[5]=z;v[8]=o;} };
struct Item {V4 v; M3 m;float f; ~Item() {} Item() {m.set(0,1);f=1;} };
struct IA {Item v[100]; ~IA() {} };
struct Prefix {int f0;void *vt;int f8;void *fC;int f10;IV v14,v24,v34;int f44;char f48[0x30];int f78,f7c,f80,f84,f88;char f8c[0x640];int f6cc,f6d0,f6d4,f6d8,f6dc,f6e0,f6e4,f6e8;V3 v6ec,v6f8,v704;V4 v710; ~Prefix();};
struct Handle { int value; ~Handle() __asm__("func_002292A0"); };
struct R: Prefix {Item arr[100];int f1d00;Handle f1d04;R *f1d08;int f1d0c,f1d10;V4 v1d14;int f1d24,f1d28;float f1d2c,f1d30,f1d34;int f1d38,f1d3c,f1d40,f1d44,f1d48,f1d4c,f1d50,f1d54;void *f1d58; ~R() __asm__("func_0022B0A0"); static void operator delete(void *);};
struct E {short delta,index;void (*fn)(void *,R *);};
extern char mRenderContext__vtable[],D_006984C0[];
extern "C" void *hObject__structor_0(void *);
extern "C" void func_00574D78(void *);
extern "C" int func_0024C7D8(void *,void *);
extern "C" void func_00229540(void *);
extern "C" void func_0022EBD8(void *);
extern "C" void *func_00326750(unsigned,int,const char *);
extern "C" void mOSKeyboard__structor_0(void *);
extern "C" void func_003285A8(void *);
extern "C" int mOSKeyboard__initialize(void *,R *);
extern "C" void func_002306D0(void *,int);

extern "C" void func_002C57D0(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_002117A0(void *);
extern "C" void func_00219030(void *,void *,int);
extern "C" void func_00211408(void *,int);
extern "C" void func_002292A0(void *,int);
extern "C" void func_0024C808(void *,int);
extern "C" void func_003286B8(void *);
extern "C" void func_00574DA8(void *,int);
extern "C" const char **func_005DB330();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void hObject__structor_2(void *,int);
static inline void arrdestroy(IA *p) {p->~IA();}
static inline void vd(IV *v, void **scratch) { int *start=(int *)v->a; int n=((int *)v->c-start);*scratch=start;if(start)func_00326798(start,n*4,4,*func_005DB330()); }
inline Prefix::~Prefix() {
 Prefix *p=this; void *spare[4]; void *scratch[4];
 func_0024C808(&p->f6d8,2);
 if(p->f88)func_003286B8((void *)p->f88);
 if(p->f84)func_003286B8((void *)p->f84);
 if(p->f80)func_003286B8((void *)p->f80);
 if(p->f7c)func_003286B8((void *)p->f7c);
 if(p->f78)func_003286B8((void *)p->f78);
 func_00574DA8(p->f48,2);
 {IV *v=&p->v34;int *start=(int *)v->a;int n=(int *)v->c-start;scratch[0]=start;if(start)func_00326798(start,n*4,4,*func_005DB330());}
 {IV *v=&p->v24;int *start=(int *)v->a;int n=(int *)v->c-start;scratch[0]=start;if(start)func_00326798(start,n*4,4,*func_005DB330());}
 {IV *v=&p->v14;int *start=(int *)v->a;int n=(int *)v->c-start;scratch[0]=start;if(start)func_00326798(start,n*4,4,*func_005DB330());}
 hObject__structor_2(p,0);
}
inline void R::operator delete(void *p) {func_00326798(p,0x1d5c,4,D_006984C0);}
R::~R() {
 R *p=this; void *tmp[4];
 p->vt=mRenderContext__vtable;func_002C57D0(p->f1d58);func_003285F8(p->f1d58);
 if(p->f1d08) {R *q=p->f1d08;E *e=(E *)((char *)q->vt+0x2d8);e->fn((char *)q+e->delta,p);}
 Handle *h=&p->f1d04;func_002117A0(tmp);func_00219030(tmp[0],h,1);func_00211408(tmp,2);
}
