/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep {int a,b,refs,owned;};
struct P {float x,y; void set(const float &a,const float &b){x=a;y=b;} };
struct Fl { unsigned a:1,b:1,c:1,d:1; void init(){a=1;b=0;c=1;d=0;} };
struct Face {int b; void *vt; char pad[0xAC]; int b4; char *str; void *bc; int c0,c4; Fl flags; P p0,p1,p2,p3; unsigned char ec,ed,ee,ef;};
extern "C" void *mColorFace__structor_0(void *);
extern "C" void func_00210810(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" char mImageFace__vtable[];
extern "C" Rep D_00659FA8;
extern "C" void mImageFace__structor_0(Face *self) {
 char **s=&self->str;
 mColorFace__structor_0(self);
 self->vt=mImageFace__vtable;
 Rep *r=&D_00659FA8; char *v=(char *)(r+1);
 if(r->owned) v=func_005C2560(r); else r->refs++;
 *s=v;
 self->bc=0;
 func_00210810(&self->c0); func_00210810(&self->c4);
 self->flags.init();
 self->ec=1;self->ed=1;self->ee=0;self->ef=0;
 float x,y;
 y=x=0.0f; self->p0.set(x,y);
 x=1.0f; y=0.0f; self->p1.set(x,y);
 x=1.0f; y=1.0f; self->p2.set(x,y);
 x=0.0f; y=1.0f; self->p3.set(x,y);
}
