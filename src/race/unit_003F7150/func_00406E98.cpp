/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_0035A540(void *,int);
extern "C" float func_0040CE10(void *);
extern "C" float func_0040CE20(void *);
extern "C" float func_0040CE30(void *);
extern "C" float func_0040CE40(void *);
extern "C" float func_0040CE50(void *);
extern "C" float func_0040CE60(void *);
extern "C" void func_0040CFB0(void *,float);
extern "C" void func_0040CFC0(void *,float);
extern "C" void func_0040CFD0(void *,float);
extern "C" void func_0040CFE0(void *,float);
extern "C" void func_0040CFF0(void *,float);
extern "C" void func_0040D000(void *,float);
static inline float maximum(float a,float b) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float minimum(float a,float b) { float r; asm("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float clamp(float a,float lo,float hi) { return minimum(maximum(a,lo),hi); }
static inline float clamp_in(float *p,float lo,float hi) { return clamp(*p,lo,hi); }
static inline void integrate(float *p,float *v,float acc,float dt) {
 *v += acc*dt;
 *p += *v*dt;
}
#define FRICTION(p,dt,zero) if(p>zero) { p-=dt; if(p<zero) p=zero; } else { p+=dt; if(p>zero) p=zero; }
extern "C" void func_00406E98(void *self,void *obj,float dt) {
 float a,b,x,v,y,w,z,u;
 a=-func_0035A540(obj,4)*30.0f;
 b=func_0035A540(obj,5);
 x=func_0040CE10(self); v=func_0040CE20(self);
 y=func_0040CE30(self); w=func_0040CE40(self);
 z=func_0040CE50(self); u=func_0040CE60(self);
 float acc=0.0f;
 a=clamp_in(&a,-0x1.4ffffep+3f,acc);
 integrate(&x,&v,(a-x)*0x1.b5c28cp+3f-v*12.0f,dt);
 FRICTION(x,dt,acc);
 x=clamp_in(&x,-1.0f,1.0f); v=clamp_in(&v,-3.0f,3.0f);
 b=clamp_in(&b,-0x1.bffffep+2f,0x1.bffffep+2f);
 integrate(&y,&w,(b-y)*0x1.b5c28cp+4f-w*12.0f,dt);
 FRICTION(y,dt,0.0f);
 y=clamp_in(&y,-1.0f,1.0f); w=clamp_in(&w,-3.0f,3.0f);
 acc=(x-z)*0x1.007ffcp+7f-u*30.0f;
 integrate(&z,&u,acc,dt);
 z=clamp_in(&z,-1.0f,1.0f); u=clamp_in(&u,-1.0f,1.0f);
 func_0040CFB0(self,x); func_0040CFC0(self,v);
 func_0040CFD0(self,y); func_0040CFE0(self,w);
 func_0040CFF0(self,z); func_0040D000(self,u);
}
