/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,w,h; Vec(float a,float b,float c,float d) {x=a;y=b;w=c;h=d;} };
struct Entry { short delta,index; int (*fn)(void *,Vec *,void *); };
struct Self { int a; Entry *vt; char pad[0x1d98]; int flag; };
struct Ctx { int a,b,c,d,e,f,g,h; float i,j; int k,l,m,n,o; };
extern "C" {
void func_00105280(Ctx *,int);Ctx *func_00105378(Ctx *,Ctx *);
int func_00105528(Ctx *);void func_001055C0(Ctx *);void func_001056A0(Ctx *);
void func_00105728(Ctx *);Ctx *func_00214F80(int) throw();int func_00215B80(Self *) throw();
void func_004A29A8(int);void func_004A2A10(int);void func_004A4550(int,int);
void pglPushAttrib(int);void func_004A5688();void func_004AB040(int);
void func_004AA1D8(float,float,float,float);
void func_004A6788(float,float,float,float,float,float,float,float);
}
extern "C" void mRenderContextPS2__virtual_67(Self *self,void *arg,float scale) {
 Vec v(0.0f,0.0f,0.0f,0.0f);
 Entry *e=self->vt+63;e->fn((char *)self+e->delta,&v,arg);
 pglPushAttrib(0x887);
 Ctx *r=func_00214F80(func_00215B80(self));
 Ctx c;Ctx *p=&c;
 func_00105378(p,r);c.b=0;func_00105528(p);func_001056A0(p);func_00105728(r);
 func_004A4550(3,1);func_004A4550(2,1);func_004AB040(4);func_004AB040(5);func_004AB040(6);
 func_004A29A8(0);func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
 float y=v.y;float x=v.x;float y2=y+v.h;float x2=x+v.w;
 float sy=y,sy2=y2;
 if(self->flag==0) {sy=y*0.5f;sy2=y2*0.5f;}
 func_004A2A10(0);
 func_004A6788(0.0f,0.0f,v.w*scale,v.h*scale,x,sy,x2,sy2);
 func_001056A0(r);func_00105728(p);func_004A2A10(1);func_004A4550(3,0);func_004A4550(2,0);
 func_004A6788(x,y,x2,y2,0.0f,0.0f,v.w*scale-1.0f,v.h*scale-1.0f);
 func_001055C0(p);func_004A5688();func_00105280(p,2);
}
