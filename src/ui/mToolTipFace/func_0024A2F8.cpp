/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Filter { float a,b,value; };
struct Obj {
 char pad[0x104]; Str text; int i108,i10c,i110,center;
 signed char state; char pad119[3];
 float width,w,h,x,y; Filter fx,fy; float speed,scale; int timer;
};
extern char D_006992C8[];
extern void *PDISTD__global_font_manager;
extern "C" void func_002471E8(void *);
extern "C" int func_0024A250(Obj *,float) throw();
extern "C" float func_0024A2A8(Obj *,float) throw();
extern "C" void mWidget__getWindowSize(Obj *,float *,float *);
extern "C" float func_00490B38(void *,const char *);
extern "C" void *func_0057B0F8(Filter *,float,float);
static inline const char *c_str(Str *s) {
 int n=*(int *)(s->p-16);
 if(n==0) return D_006992C8;
 s->p[n]=0;
 return s->p;
}
static inline void reset(Filter *s,float v) { s->value=v; s->a=0; s->b=0; }
extern "C" void func_0024A2F8(Obj *s) {
 float wait,step;
 if(s->i10c==0) { wait=0.2f; step=128.0f; }
 else { wait=0.0f; step=10000.0f; }
 switch(s->state) {
 case 0:
  func_002471E8((char *)s+0xa0);
  s->width=func_00490B38(PDISTD__global_font_manager,c_str(&s->text));
  mWidget__getWindowSize(s,&s->w,&s->h);
  if(s->width <= s->w*0.95f) { s->center=1; s->x=(s->w-s->width)*0.5f; s->y=s->h; reset(&s->fx,s->x); reset(&s->fy,s->y); }
  else { s->center=0; s->x=s->w*0.05f; s->y=s->h; reset(&s->fx,s->x); reset(&s->fy,s->y); }
  s->timer=func_0024A250(s,wait);
  ++s->state;
 case 1:
  if(--s->timer<0) ++s->state;
  break;
 case 2:
  if(s->y>0.0f) s->y-=func_0024A2A8(s,step);
  if(s->y<=0.0f) {
   s->y=0.0f;
   if(s->center) s->state=100;
   else { s->timer=func_0024A250(s,s->w*0.4f/s->speed/s->scale); ++s->state; }
  }
  break;
 case 3:
  if(--s->timer<0) s->state=10;
  break;
 case 4:
  if(s->i110) s->x-=func_0024A2A8(s,s->speed*s->scale)*0.5f;
  else s->x-=func_0024A2A8(s,s->speed*s->scale);
  if(s->x < -(s->width-s->w)) { s->timer=func_0024A250(s,s->w*0.75f/s->speed/s->scale); ++s->state; }
  break;
 case 5:
  if(--s->timer<0) ++s->state;
  break;
 case 6:
  if(s->y<s->h) s->y+=func_0024A2A8(s,step);
  if(s->y>=s->h) {
   s->x=s->w*0.05f; s->y=s->h;
   reset(&s->fx,s->x); reset(&s->fy,s->y);
   s->timer=func_0024A250(s,1.0f); s->state=1;
  }
  break;
 case 10:
  s->x-=func_0024A2A8(s,s->speed*s->scale);
  if(s->x < -s->width) { s->timer=func_0024A250(s,1.0f); ++s->state; }
  break;
 case 11:
  if(--s->timer<0) {
   s->x=s->w*0.05f; s->y=s->h;
   reset(&s->fx,s->x); reset(&s->fy,s->y);
   s->timer=func_0024A250(s,1.0f); s->state=1;
  }
  break;
 case 100:
 default: break;
 }
 func_0057B0F8(&s->fx,s->x,0.1f);
 func_0057B0F8(&s->fy,s->y,0.3f);
}
