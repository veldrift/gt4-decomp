/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { char pad[0x3f0]; int hit; int special; char pad2[4]; float time; char rest[0xf0]; };
struct Obj { int x, count, y; Item items[1]; };
struct Car { char pad[0x54c]; float value; };
extern "C" {
Car *func_0045B8A8(Obj *, int) throw();
int func_00343BF0(void *);
void func_0045C488(void *,float);
void func_0045C530(void *,int);
void func_0045C578(void *);
void func_0045C5A8(void *);
void func_0045C648(void *);
void func_0045C668(void *,float);
void func_0045C9F8(void *);
void func_0045CA60(void *,float);
void func_0045CC60(void *,void *);
int func_0045D8E0(void *);
void func_0045DB78(void *,float);
void func_0045DF80(void *);
void func_0045E028(void *);
void func_0045E570(void *);
void func_0045ECB0(void *,int);
void func_0045F340(void *);
void func_0045FAD0(void *,int);
void func_0045BB60(Obj *p) {
 float finalTime=1.0f;
 int i,j;
 for(i=0;i<p->count;i++) {
  func_0045C488(&p->items[i],func_0045B8A8(p,i)->value);
  func_0045C530(&p->items[i],func_00343BF0(func_0045B8A8(p,i))==0);
 }
 for(int pass=0;pass<2;pass++) {
  for(i=0;i<p->count;i++) for(j=0;j<p->count;j++) if(i!=j) func_0045FAD0(&p->items[i],j);
  for(i=0;i<p->count;i++) func_0045C578(&p->items[i]);
  for(i=0;i<p->count;i++) func_0045C5A8(&p->items[i]);
  int selected=-1; float time=2.0f;
  for(i=0;i<p->count;i++) {
   func_0045C648(&p->items[i]);
   if(func_0045D8E0(&p->items[i])) {
    float t=p->items[i].time;
    if(t<time) {time=t;selected=i+0x200;}
   }
   for(j=0;j<p->count;j++) if(i!=j) func_0045ECB0(&p->items[i],j);
   if(p->items[i].hit) {
    float t=p->items[i].time;
    if(t<time) {time=t;selected=i;}
   }
  }
  for(i=0;i<p->count;i++) func_0045DB78(&p->items[i],time);
  if(selected<0) break;
  finalTime=time;
  for(i=0;i<p->count;i++) func_0045C668(&p->items[i],time);
  if(selected&0x200) {
   if(p->items[selected&~0x200].special) func_0045E028(&p->items[selected&~0x200]);
   else func_0045E570(&p->items[selected&~0x200]);
  } else func_0045F340(&p->items[selected]);
 }
 for(i=0;i<p->count;i++) {
  func_0045CA60(&p->items[i],finalTime);
  func_0045DF80(&p->items[i]);
  func_0045C9F8(&p->items[i]);
  func_0045CC60(&p->items[i],func_0045B8A8(p,i));
 }
}
}
