/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Rec {u8 type,n;char p[0x12];u8 indices[8];};
struct Element {float x;char p[0x54];};
struct Params {char p[0xc];float f18,f1c,f20,f24;char q[0x300-0x1c];Element elems[8];};
struct Owner {char p[0xc];Params params;};
struct Data {float v[3],basis[9],pad30[3],a[3],b[3];char p[0x4b5-0x54];u8 mode;char q[0x544-0x4b6];float vel[3];char r[0x568-0x550];float pitch,roll,yaw;char s[0x5b4-0x574];float f5b4;};
struct Obj {char p[0x10];Owner*owner;char q[0xf0];Data data;};
extern "C" Rec* func_00359510(Owner*);
extern "C" void func_003457B0(Obj*);
extern "C" void func_0036A080(Obj*,float) throw();
extern "C" int func_0036A1D8(Obj*,int) throw();
extern "C" void func_0036C9F8(float*,float*,float*,float,float,float);
extern "C" float func_0057D118(float,float);
inline int index(Rec*r,int i){if(i>=r->n)return 0;return r->indices[i];}
extern "C" void func_0036BA88(Obj*o){
 float heights[8];Data*d=&o->data;Owner*p=o->owner;Rec*r=func_00359510(p);
 if(d->mode){func_003457B0(o);func_0036A080(o,d->f5b4);d->mode=func_0036A1D8(o,d->mode*16);
 if(d->mode&15){float total=0.0f;
 for(int i=0;i<r->n;++i){Params*t=&p->params;heights[i]=t->elems[index(r,i)].x-((float*)((char*)o+0x514))[i];if(heights[i]<0.0f)heights[i]=0.0f;}
 float front=0.0f,back=0.0f,right=0.0f,left=0.0f;
 switch((int)r->type){
 case 0:front=(heights[0]+heights[1])*0.5f;back=(heights[2]+heights[3])*0.5f;left=heights[0]+(heights[2]-heights[0])*p->params.f20;right=heights[1]+(heights[3]-heights[1])*p->params.f20;break;
 case 1:front=heights[0];back=heights[1];break;
 case 2:front=heights[0];back=(heights[1]+heights[2])*0.5f;left=front+(heights[1]-front)*p->params.f20;right=front+(heights[2]-front)*p->params.f20;break;
 case 3:back=heights[2];front=(heights[0]+heights[1])*0.5f;left=back+(heights[0]-back)*p->params.f24;right=back+(heights[1]-back)*p->params.f24;break;
 }
 if(left!=0.0f||right!=0.0f){if(right<left){d->roll+=func_0057D118(left-right,p->params.f1c);total=right*0.5f;}else if(left<right){d->roll+=func_0057D118(left-right,p->params.f1c);total=left*0.5f;}else total=left*0.5f;}
 if(front!=0.0f||back!=0.0f){float add;if(back<front){d->pitch+=func_0057D118(front-back,p->params.f18);add=back*0.5f;}else if(front<back){d->pitch+=func_0057D118(front-back,p->params.f18);add=front*0.5f;}else add=front*0.5f;total+=add;}
 d->v[2]+=total;
 }
 func_0036C9F8(d->basis,d->basis+3,d->basis+6,d->pitch,d->roll,d->yaw);
 float x=0.0f,y=0.0f;
 for(int i=0;i<3;++i){float v=d->vel[i];x+=d->a[i]*v;y+=d->b[i]*v;}
 float z=x*d->a[2]+y*d->b[2];if(z>0.0f)z=0.0f;if(d->vel[2]<z)d->vel[2]=z;
 }
}
