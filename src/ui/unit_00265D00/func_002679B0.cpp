/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { char *p; char pad[12]; };
struct Obj { char pad[0x68]; Handle h; };
extern "C" {
void func_0024B218(void *, void *);
void func_0024B248(void *, int);
void func_0024BDB8(void *);
void func_0024BE78(void *, float, float);
void func_0024BEB0(void *, float, float);
void func_0024BEF8(void *, float);
void func_0024BFA0(void *, float);
void func_0024C000(void *, float);
void mWidget__getWindowSize(void *, float *, float *) throw();
void func_003285A8(void *);
void func_003285F8(void *);
bool func_004899E8(void *, void *) throw();
void func_005769F0(void *);
void func_00576A28(void *);
int func_005A2ED0(void *);
void func_00269248();
extern int D_00619370;
extern float D_00830770[9];
extern char D_00830A18[];
}
static inline bool ne(void *a, void *b) { return !func_004899E8(a, b); }
static inline float getf(float *p) { return *p; }
static inline void identity(float *m, float z, float o) {
 m[0]=o; m[3]=z; m[6]=z; m[1]=z; m[4]=o; m[7]=z; m[2]=z; m[5]=z; m[8]=o;
}
static inline void assign(Handle *dst, Handle *src) {
 if(dst!=src) {
  char *n=src->p;
  if(n) func_003285A8(n);
  char *o=dst->p;
  if(o) func_003285F8(o);
  dst->p=n;
 }
}
extern "C" void func_002679B0(char *self) {
 Handle h;
 float w, y;
 Handle h2;
 char *zero;
 char *newVal, *oldVal;
 *(int *)(self+0x98) &= 0xffdfffff;
 func_0024BDB8(&h);
 float x=*(float *)(self+0x78);
 if(x!=0.0f || getf((float *)(self+0x7c))!=0.0f)
   func_0024BEB0(h.p,x,getf((float *)(self+0x7c)));
 if(*(float *)(self+0x74)!=0.0f || getf((float *)(self+0x6c))!=1.0f || getf((float *)(self+0x70))!=1.0f || getf((float *)(self+0x80))!=0.0f || getf((float *)(self+0x84))!=0.0f) {
   mWidget__getWindowSize(self,&w,&y);
   func_0024BEB0(h.p,w*0.5f,y*0.5f);
   x=*(float *)(self+0x74);
   if(x!=0.0f) func_0024BEF8(h.p,x);
   x=getf((float *)(self+0x6c));
   if(x!=1.0f || getf((float *)(self+0x70))!=1.0f) func_0024BE78(h.p,x,getf((float *)(self+0x70)));
   x=getf((float *)(self+0x84));
   if(x!=0.0f) func_0024C000(h.p,x);
   x=getf((float *)(self+0x80));
   if(x!=0.0f) func_0024BFA0(h.p,x);
   func_0024BEB0(h.p,-w*0.5f,-y*0.5f);
 }
 if(!D_00619370) {
   D_00619370=1;
   identity(D_00830770,0.0f,1.0f);
   func_005A2ED0((void *)func_00269248);
 }
 func_005769F0(D_00830A18);
 if(ne(h.p+0x10,D_00830770)) {
   assign((Handle *)(self+0x68),&h);
 } else {
   Handle *ph2=&h2;
   zero=0;
   func_0024B218(ph2,&zero);
   assign((Handle *)(self+0x68),ph2);
   func_0024B248(ph2,2);
 }
 func_00576A28(D_00830A18);
 func_0024B248(&h,2);
}
