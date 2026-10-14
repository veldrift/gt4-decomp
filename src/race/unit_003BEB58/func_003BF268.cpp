/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[12]; Node *next; int p10,id; };
struct List { char pad[8]; Node **entries; char gap[12]; Node *head; };
struct Context { char pad[0x60]; List *list; };
struct Texture { char pad[0x20]; unsigned long bits; };
struct Image { char pad[0x18]; Texture *tex; };
struct Resource { char pad[0x28]; Image *image; char gap[8]; unsigned short w,h; };
struct Self { char pad[0x18]; Resource *res; char gap[0x24]; int mode,ready; float pulse; };
struct Target { int id,flags,w,h; };
extern "C" {
void func_00105460(Target*,int,int);
int func_00105528(Target*);
void func_001056A0(Target*);
void func_003AED70(void*,float,float,float);
int func_003AFEC8(int,float);
void func_003BED80(void*) throw();
void func_003BF150(Self*,Node*,int,unsigned int,float) throw();
void func_004A1638(int);
void func_004A2750(int,float);
void func_004A27C8(int);
void func_004A2808(int,float);
void func_004A2980(int);
void func_004A29A8(int);
void func_004A3078(int);
void func_004A3230(int);
void RaceEntryCar__update(int);
void func_004A53F8();
void func_004A5400();
void pglPushAttrib(int);
void func_004A5688();
void func_004A5A90(float,float,float,float,float,float);
void func_004A7454();
void func_004A7844(float,float,float);
void func_004A7890(float,float,float);
void func_004AA168(unsigned int);
void func_004AB040(int);
}
static inline float minf(float a,float b) { float r; __asm__("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void func_003BF268(Self *s,Target *t,Context *ctx,int idx) {
 if(!s->ready) func_003BED80(s);
 Image *im=s->res->image;
 if(im) {
  pglPushAttrib(0x81);
  unsigned long bits=im->tex->bits;
  int iw=((bits>>14)&0x3ff)+1;
  int ih=((bits>>34)&0x3ff)+1;
  int hw=s->res->w, hh=s->res->h;
  if(hw==0 || hh==0) { hw=iw>>1; hh=ih>>1; }
  int w=hw*2, h=hh*2;
  if(t->id==-1) { func_00105460(t,w,h); t->flags=0; func_00105528(t); }
  func_001056A0(t);
  func_004A2980(-1); func_004A3078(0); func_004A3230(1);
  func_004A1638(6); func_004A1638(4); func_004AB040(15); func_004AB040(5); func_004A29A8(0);
  func_004A2808(0x44,0); func_004A2750(6,0); func_004A27C8(0);
  RaceEntryCar__update(1); func_004A53F8(); func_004A7454();
  float tw=t->w, th=t->h;
  func_004A5A90(0,tw,th,0,-1,1);
  RaceEntryCar__update(0); func_004A53F8(); func_004A7454();
  func_004A7844(tw-w*0.5f,th-h*0.5f,0);
  float scale=minf(tw/w,th/h); scale=minf(scale,1);
  func_004A7890(scale,scale,1);
  Node *selected=ctx->list->entries[idx];
  if(!s->mode) func_003BF150(s,selected,1,0x80000000,1);
  func_004AA168(0x80ffffff);
  func_004A2808(0x64,1); func_004A2750(6,0.2f);
  func_003AED70(s->res->image,0,0,1);
  func_004A2808(0x44,0); func_004A2750(6,0);
  for(Node *n=ctx->list->head;n;n=n->next) if(n->id!=idx) func_003BF150(s,n,0,0x80ffffff,1);
  if(!s->mode) {
   func_004A1638(4); func_004A2750(6,0.5f); func_004A27C8(0);
   func_003BF150(s,selected,1,func_003AFEC8(0x80ffffff,s->pulse*0.7f+0.3f),1);
  } else func_003BF150(s,selected,1,0x805ea8f2,1);
  func_004AB040(4); func_004A5400(); RaceEntryCar__update(1); func_004A5400(); RaceEntryCar__update(0); func_004A5688();
 }
}
