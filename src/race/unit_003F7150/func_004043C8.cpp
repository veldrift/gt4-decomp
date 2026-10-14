/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { int a0; int pad4; int a8; char pad[0xfc]; float force; int pad10c; float dt; };
extern "C" float *func_00385AE8(int);
extern "C" float *func_00385B08(int);
extern "C" float *func_003861C8(int);
extern "C" float *func_003861E8(int);
extern "C" float *func_00386358(int);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
extern "C" float func_0044F8B0(void *);
extern "C" float func_0044F8C0(void *);
struct St { float acc; float *vel; float *pos; };
static inline float minimum(float a,float b) { float r; asm("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float maximum(float a,float b) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline void friction(St *s,float f) { float a=s->acc; if(a*a<f*f) s->acc=0.0f; else s->acc=a>0.0f?a-f:a+f; }
static inline void advance(St *s,float dt) { *s->pos+=*s->vel*dt; s->acc=0.0f; }
static inline void spring(St *s,float target,float dt,float k,float d,float vmax) {
 s->acc += (target-*s->pos)*k;
 s->acc -= *s->vel*d;
 *s->vel += s->acc*dt;
 float v=*s->vel;
 if(v*v>vmax*vmax) { if(v>0.0f) *s->vel=vmax; else *s->vel=-vmax; }
 advance(s,dt);
}
static inline void fix(St *s,float p) { s->acc=0.0f; *s->vel=0.0f; *s->pos=p; }
extern "C" int func_004043C8(W *w,float limit,float target) {
 int result=0;
 float z=0.0f, damping=20.0f, stiffness=0x1.67fffep+6f;
 St s,t;
 float *v=func_003861E8(w->a8); float *p=func_00385B08(w->a0);
 s.vel=v; s.pos=p; s.acc=z;
 St *tp=&t;
 v=func_003861C8(w->a8); p=func_00385AE8(w->a0);
 tp->acc=z; t.vel=v; t.pos=p;
 func_00385B08(w->a0);
 float force=w->force; float cap=w->dt*4000.0f;
 float goal=target+func_0044F8C0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
 float c=2000.0f;
 float sum=force+*func_00386358(w->a8);
 if(cap<sum) {
  result=1; *func_00386358(w->a8)=sum-cap; force=cap;
  float *out=func_00386358(w->a8); *out=minimum(c,*func_00386358(w->a8));
 } else if(sum < -cap) {
  force=-cap; result=1; *func_00386358(w->a8)=sum+cap;
  float *out=func_00386358(w->a8); *out=maximum(-c,*func_00386358(w->a8));
 } else { force=sum; *func_00386358(w->a8)=z; }
 limit+=func_0044F8B0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
 s.acc+=force; friction(&s,3.0f); spring(&s,goal,w->dt,stiffness,damping,0x1.f6a7ap+4f);
 if(limit<*s.pos) fix(&s,limit); else if(*s.pos<0.0f) fix(&s,0.0f);
 if(limit*0.25f<=*s.pos || *s.pos==0.0f) tp->acc+=force;
 friction(tp,3.0f); spring(&t,0.0f,w->dt,stiffness,damping,0x1.f6a7ap+4f);
 float lo=-0.26179934f, hi=0.26179934f;
 if(*t.pos>hi) fix(&t,hi); else if(*t.pos<lo) fix(&t,lo);
 return result;
}
