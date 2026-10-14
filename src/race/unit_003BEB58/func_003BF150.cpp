/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {char pad[0x18]; void *view; void *icons[6]; char pad34[12]; int mode;};
struct Car {char pad[0x18]; void *obj; char gap[0x3428]; int type;};
extern "C" {
float func_00344798(void*,float);
float func_00344828(void*,float);
int Automobile__getDrawMode(void*);
void func_003AED70(void*,float,float,float);
void func_003BEBA0(void*,float*,float*,float,float) throw();
void func_004AA168(unsigned int);
}
static inline unsigned int alpha(unsigned int c,unsigned int a) { return (a<<24)|(c&0xffffff); }
extern "C" void func_003BF150(Self*s,Car*c,int selected,unsigned int color,float size) {
 int i=selected==0;
 void *obj=c->obj;
 if(s->mode) i=c->type;
 void *icon=*(void**)((char*)s+i*4+0x1c);
 int mode=Automobile__getDrawMode(obj);
 
 switch(mode) {
 case 0: return;
 case 1: return;
 case 2: color=alpha(color,(color>>24)/2);
 case 3: {
  func_004AA168(color);
  float x=func_00344798(obj,0.0f);
  float y=func_00344828(obj,0.0f);
  float px,py;
  func_003BEBA0(s->view,&px,&py,x,y);
  func_003AED70(icon,px,py,size);
  return;
 }
 }
}
