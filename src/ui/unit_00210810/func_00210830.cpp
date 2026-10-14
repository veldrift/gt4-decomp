/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x,y,z,w; void set(float a,float b,float c,float d) { x=a;y=b;z=c;w=d; } };
struct Elem { int flag; float f[4]; Vec4 v[4]; };
struct Obj { int m; Vec4 v; Elem e[4]; };
extern "C" void func_002030A0(Vec4 *);
extern "C" void func_00210830(Obj *self) {
  Vec4 *vp=&self->v;
  Elem *p=self->e;
  func_002030A0(vp);
  for(int i=3;i!=-1;--i) {
    func_002030A0(&p->v[0]);func_002030A0(&p->v[1]);func_002030A0(&p->v[2]);func_002030A0(&p->v[3]);++p;
  }
  self->m=0;
  self->e[0].flag=1;self->e[1].flag=0;self->e[2].flag=0;self->e[3].flag=0;
  vp->set(0,0,0,1);
  for(int j=0;j<4;++j) {
    self->e[j].f[0]=0;self->e[j].f[1]=1;self->e[j].f[2]=0;self->e[j].f[3]=0;
    self->e[j].v[0].set(0.3f,0.3f,0.3f,1);
    self->e[j].v[1].set(0.5f,0.5f,0.5f,1);
    self->e[j].v[2].set(0.5f,0.5f,0.5f,1);
    self->e[j].v[3].set(0,0,0,1);
  }
}
