/* compiler: ee-gcc2.96-no-strict-aliasing */
inline void *operator new(unsigned int, void *p) { return p; }
struct Alloc {};
struct IV { int unused, a,b,c; IV(const Alloc &a0=Alloc()) { a=0;b=0;c=0; } };
struct V3 { float x,y,z; void set(float a,float b,float c) {x=a;y=b;z=c;} };
struct V4 { float x,y,z,w; V4(float a=0,float b=0,float c=0,float d=0):x(a),y(b),z(c),w(d) {} void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;} };
struct VA { V4 v[100]; };
struct M3 {float v[9]; void set(float z,float o) {v[0]=o;v[3]=z;v[6]=z;v[1]=z;v[4]=o;v[7]=z;v[2]=z;v[5]=z;v[8]=o;} };
struct Item {V4 v; M3 m;float f; Item() {m.set(0,1);f=1;} };
struct IA {Item v[100];};
struct R {int f0;void *vt;int f8;void *fC;int f10;IV v14,v24,v34;int f44;char f48[0x30];int f78,f7c,f80,f84,f88;char f8c[0x640];int f6cc,f6d0,f6d4,f6d8,f6dc,f6e0,f6e4,f6e8;V3 v6ec,v6f8,v704;V4 v710;char f720[0x15e0];int f1d00,f1d04;R *f1d08;int f1d0c,f1d10;V4 v1d14;int f1d24,f1d28;float f1d2c,f1d30,f1d34;int f1d38,f1d3c,f1d40,f1d44,f1d48,f1d4c,f1d50,f1d54;void *f1d58;};
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
extern "C" void mRenderContext__structor_0(R *p,int arg1) {
 int spare[4];
 hObject__structor_0(p);p->vt=mRenderContext__vtable;p->f10=arg1;
 new (&p->v14) IV;new (&p->v24) IV;new (&p->v34) IV;p->f44=0;func_00574D78(p->f48);
 p->f78=0;p->f7c=0;p->f80=0;p->f84=0;p->f88=0;new (p->f8c) VA;
 p->f6cc=-1;p->f6d0=1;p->f6d4=0;void *zero=0;func_0024C7D8(&p->f6d8,&zero);
 p->f6dc=0;p->f6e0=0;p->f6e4=1;p->f6e8=5;
 p->v6ec.set(0,0,0);p->v6f8.set(0,0,0);p->v704.set(0,0,0);p->v710.set(0,0,640,480);
 new (p->f720) IA;p->f1d00=-1;func_00229540(&p->f1d04);
 p->f1d08=0;p->f1d0c=0;p->f1d10=0;p->v1d14.set(0,0,0,0);
 p->f1d24=8;p->f1d28=0;p->f1d2c=320;p->f1d30=240;p->f1d34=0;
 p->f1d38=0;p->f1d3c=0;p->f1d40=0;p->f1d44=0;p->f1d48=0;p->f1d50=1;p->f1d54=0;p->f1d58=0;
 func_0022EBD8(p);
 if(p->f1d08) {R *q=p->f1d08;E *e=(E *)((char *)q->vt+0x2d0);e->fn((char *)q+e->delta,p);}
 void *q=func_00326750(0x68,4,D_006984C0);mOSKeyboard__structor_0(q);p->f1d58=q;func_003285A8(q);mOSKeyboard__initialize(p->f1d58,p);func_002306D0(p,1);spare[0]=0;
}
