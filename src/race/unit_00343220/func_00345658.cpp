/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { float x,v,a,y,w; char pad[0x1c]; };
struct World { char pad[0xCAB8]; State s[16]; };
struct Params { char pad[0x440]; unsigned char index; char q[0x127]; float targetY; char r[4]; float targetX; char t[0x88]; float outX,outY; };
struct Obj { char p[4]; World *world; };
extern "C" float D_0069F4C8,D_0069F4D0;
extern "C" float func_0036CB90(float);
extern "C" float func_0036CC40(float,float);
extern "C" void func_00345658(Obj *self) {
 Params *p=(Params *)((char *)self+0x104);
 float k=D_0069F4C8;
 float damping=D_0069F4D0;
 float dt=0x1.11111p-6f;
 float k2=20.0f;
 float d2=10.0f;
 State *s=self->world->s+p->index;
 float force=func_0036CC40(p->targetX,s->x)*k-s->v*damping;
 float sum=s->a+force;
 s->a=force;
 s->v=s->v+sum*0.5f*dt;
 s->x=s->x+s->v*dt;
 s->x=func_0036CB90(s->x);
 p->outX=func_0036CC40(p->targetX,s->x);
 force=func_0036CC40(p->targetY,s->y)*k2-s->w*d2;
 s->w=s->w+force*dt;
 s->y=s->y+s->w*dt;
 s->y=func_0036CB90(s->y);
 p->outY=func_0036CC40(p->targetY,s->y);
}
