/* compiler: ee-gcc2.96-no-strict-aliasing */
union I { int i; float f; };
struct W { I a0; int pad4; I a8; int padc; int *a10; int a14; char pad18[0xF8]; float dt; };
union P { float *p; int i; };
struct St { float acc; P vel,pos; };
extern "C" {
float func_003856A8(int);
float *func_00385D78(int); float *func_00385E68(int); float *func_00385E78(int);
float *func_003864D8(int); float *func_00386508(int); float *func_00386588(int); float *func_00386598(int);
int func_00402270(int,int) throw();
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline void step(St *s,float dt,float damping) {
 s->acc-=*s->vel.p*damping;
 *s->vel.p+=s->acc*dt;
 *s->pos.p+=*s->vel.p*dt;
 s->acc=0.0f;
}
static inline float absf(float x) { float r; __asm__("abs.s %0, %1":"=f"(r):"f"(x)); return r; }
extern "C" void func_00405800(W *w) {
 St s,a,b;
 float zero=0.0f;
 float target=func_003856A8(w->a0.i)*0.25f;
 float *vel=func_00386508(w->a8.i);
 float *pos=func_00385D78(w->a0.i);
 s.vel.p=vel; s.pos.p=pos; s.acc=zero;
 float magnitude=absf(*func_00385D78(w->a0.i));
 float targetMagnitude=absf(target);
 if(magnitude < targetMagnitude) {
   float dt=w->dt;
   s.acc+=(target-*s.pos.p)*4.0f;
   step(&s,dt,4.0f);
 } else {
   float dt=w->dt;
   s.acc+=(target-*s.pos.p)*100.0f;
   step(&s,dt,20.0f);
 }
 float gain=0.1f;
 switch(func_00402270(w->a14,*w->a10)) {
 case 1: gain=0.0f; break;
 case 3: case 4: case 5: gain=0.25f; break;
 }
 float zero2=0.0f;
 St *pa=&a;
 float *va=func_00386588(w->a8.i);
 float *xa=func_00385E68(w->a0.i);
 pa->acc=zero2; pa->vel.p=va; pa->pos.p=xa;
 St *pb=&b;
 float *vb=func_00386598(w->a8.i);
 float *xb=func_00385E78(w->a0.i);
 pb->acc=zero2; pb->vel.p=vb; pb->pos.p=xb;
 float ratio=*func_003864D8(w->a8.i)/0x1.0c152p-2f;
 if(ratio<zero2) {
   ratio=minf(maxf(-ratio,zero2),1.0f)*gain+0.1f;
   float dt=w->dt;
   pa->acc+=(ratio-*pa->pos.p)*50.0f;
   pb->acc+=(0.1f-*pb->pos.p)*25.0f;
   step(pa,dt,14.14f);
   step(pb,w->dt,10.0f);
 } else {
   ratio=minf(maxf(ratio,zero2),1.0f)*gain+0.1f;
   float dt=w->dt;
   pa->acc+=(0.1f-*pa->pos.p)*25.0f;
   pb->acc+=(ratio-*pb->pos.p)*50.0f;
   step(pa,dt,10.0f);
   step(pb,w->dt,14.14f);
 }
}
