/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void *mGTShirt__structor_0(void *);
void func_001C2018(void *) throw();
void func_001C20D8(void *) throw();
void func_001C2030(void *) throw();
void func_001C2110(void *, unsigned, unsigned) throw();
void *func_001C1620(int) throw();
void func_001C1A50(void *, unsigned, unsigned, void *, unsigned, unsigned) throw();
void func_001C3958(void *);
void *func_002556B0(void *);
void func_00574D78(void *);
void *func_005A48D8(void *, int, unsigned);
void *func_005A4724(void *, const void *, unsigned);
void free(void *) throw();
int func_004AE230(void *, const char *, int);
int func_00578B50(unsigned, int);
int func_00578610(int);
int func_00575098(void *, int);
int func_005788B8(int);
void func_001C4248(void *);
}
extern char mGTShirtPS2__vtable[], D_00693C68[];
struct E { unsigned w,h,stride,size; void *buf,*b1,*b2; E() {func_001C2018(this);} };
static inline void down(E *d, E *s) { func_001C1A50(d->buf,d->w,d->h,s->buf,s->w,s->h); }
static inline unsigned bytes(E *p) { unsigned h=p->h; return p->stride*h; }
struct F { char data[0x4c]; F() {func_001C20D8(this);} };
struct EA { E a[4]; }; struct FA { F a[4]; };
inline void *operator new(unsigned, void *p) { return p; }
struct Blob { int a[6]; };
struct O {
 int x; void *vt; int y,z;
 E a[4],b[4],c;
 F d[4];
 int p23c,p240; float p244,p248,p24c,p250;
 int p254,p258,p25c,p260; char *p264,*p268,*p26c;
 unsigned p270,p274; int p278,p27c,p280,p284,p288,p28c,p290;
 Blob previous,current;
 int p2c4,p2c8,p2cc,p2d0,p2d4,p2d8;
 int widget; char mutex[0x30];
 int p310,p314,p318,p31c,p320,p324,p328;
};
struct File { char pad[16]; char *data; char pad2[12]; };
struct Thread { void (*fn)(void *); O *arg; };
extern "C" void mGTShirtPS2__structor_0(O *o) {
 File file; Thread thread;
 mGTShirt__structor_0(o); o->vt=mGTShirtPS2__vtable;
 new (o->a) EA; new (o->b) EA; new (&o->c) E; new (o->d) FA;
 o->p23c=160; o->p240=160; o->p244=.75f; o->p248=.25f; o->p24c=.18f; o->p250=-.01f;
 o->p254=41; o->p258=15; o->p25c=10;
 o->p260=0; o->p264=0; o->p268=0;
 o->p270=320; o->p274=240; o->p278=0; o->p27c=1; o->p280=0; o->p284=0; o->p288=0; o->p28c=0; o->p290=0;
 o->p2c4=-1; o->p2c8=-1; o->p2cc=0; o->p2d0=0; o->p2d4=0; o->p2d8=0;
 func_002556B0(&o->widget); func_00574D78(o->mutex);
 o->p310=0; o->p314=0; o->p318=0; o->p31c=0; o->p320=0; o->p324=0; o->p328=0;
 func_005A48D8(&o->previous,0,24); o->current=o->previous;
 o->p260=0x4b000; o->p264=(char *)func_001C1620(0xe1000); o->p268=o->p264+o->p260; o->p26c=o->p268+o->p260;
 func_004AE230(&file,D_00693C68,1);
 char *data=file.data;
 o->b[0].w=*(unsigned *)(data+4); o->b[0].h=*(unsigned *)(data+8);
 func_001C2030(&o->b[0]);
 func_005A4724(o->b[0].buf,data+16,bytes(&o->b[0]));
 free(data);
 for(int i=1;i<4;i++) {
  o->b[i].w=(o->b[i-1].w+1)>>1; o->b[i].h=(o->b[i-1].h+1)>>1;
  func_001C2030(&o->b[i]);
  down(&o->b[i],&o->b[i-1]);
 }
 for(int i=0;i<4;i++) func_001C2110(&o->d[i],o->b[i].w,o->b[i].h);
 func_001C3958(o);
 o->a[0].w=o->p270; o->a[0].h=o->p274;
 for(int i=1;i<4;i++) { o->a[i].w=(o->a[i-1].w+1)>>1; o->a[i].h=(o->a[i-1].h+1)>>1; }
 for(int i=0;i<4;i++) func_001C2030(&o->a[i]);
 o->c.w=o->p270; o->c.h=o->p274; func_001C2030(&o->c);
 Thread *pt=&thread; pt->fn=func_001C4248; pt->arg=o;
 int t=func_00575098(pt,func_00578610(func_00578B50(2,0)));
 func_005788B8(t); o->p310=t;
}
