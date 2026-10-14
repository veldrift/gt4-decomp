/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[12]; Node *next; int p10,id; };
struct List { char pad[8]; Node **entries; char gap[12]; Node *head; };
struct Context { char pad[0x60]; List *list; };
struct Resource { char pad[0x28]; void *p28; };
struct Self { unsigned char active,fx,fy,p3; short x,y; int p8; float alpha; char pad10[8]; Resource *res; char pad1c[0x18]; float sx,sy; short w,h; int mode,ready; float pulse; };
extern "C" {
void func_003AED70(void*,float,float,float);
float func_003AFD18(int,float,float);
int func_003AFEC8(int,float);
void func_003BED80(void*) throw();
void func_003BF150(Self*,Node*,int,int,float);
void func_004A1638(int);
void func_004A2750(int,float);
void func_004A27C8(int);
void func_004A2808(int,float);
void func_004A53F8();
void func_004A5400();
void func_004A7844(float,float,float);
void func_004A7890(float,float,float);
void func_004AA168(int);
void func_004AB040(int);
}
extern "C" void func_003BEE78(Self *s,void *ctx,int idx) {
 if(s->active) {
  if(!s->ready) func_003BED80(s);
  func_004A53F8();
  float w=(float)s->w*s->sx;
  float h=(float)s->h*s->sy;
  float x=func_003AFD18(s->fx,(float)s->x,w)+w*0.5f;
  float y=func_003AFD18(s->fy,(float)s->y,h)+h*0.5f;
  func_004A7844(x,y,0.0f);
  func_004A7890(s->sx,s->sy,1.0f);
  List *l=((Context*)ctx)->list;
  Node *selected=l->entries[idx];
  func_004A1638(6);
  func_004A2808(0x44,0.0f);
  if(!s->mode) func_003BF150(s,selected,1,func_003AFEC8(0x80000000,s->alpha),1.0f);
  func_004AA168(func_003AFEC8(0x80ffffff,s->alpha));
  func_003AED70(s->res->p28,0.0f,0.0f,1.0f);
  List *all=((Context*)ctx)->list;
  int color=func_003AFEC8(0x80ffffff,s->alpha);
  Node *n=all->head;
  for(;n;n=n->next) {
   if(n->id!=idx) func_003BF150(s,n,0,color,1.0f);
  }
  if(selected) {
   if(!s->mode) {
    func_004A1638(4);
    func_004A2750(6,0.5f);
    func_004A27C8(0);
    float pulse=s->pulse;
    func_003BF150(s,selected,1,func_003AFEC8(0x80ffffff,s->alpha*pulse*0x1.666666p-1f+0x1.333332p-2f),1.0f);
    func_004AB040(4);
   } else func_003BF150(s,selected,1,func_003AFEC8(0x805ea8f2,s->alpha),1.0f);
  }
  func_004A5400();
 }
}
