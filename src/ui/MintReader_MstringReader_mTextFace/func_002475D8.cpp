/* compiler: ee-gcc2.96-no-strict-aliasing */
struct String { char *p; };
struct Style {
 float color[4]; String text;
 int a14,a18,a1c,a20,a24,a28;
 float a2c,a30,a34,a38,a3c,shadow[4];
 int a50;
};
struct Font {
 char pad[0x24]; float x,y; int a2c;
 char pad30[0x14]; unsigned int color,shadow; int flag;
 char pad50[0x14]; int a64,a68,a6c; float a70; int a74;
};
extern Font *D_00624984;
extern char D_006991B0[];
extern "C" void func_00490290(Font *,const char *);
extern "C" unsigned int func_00202EA8(float *,float);
extern "C" void func_0025BAA0(void *,float *,float *,float *,float *);
extern "C" void func_00490700(Font *,int,int,int,int);
extern "C" int func_00490740(Font *,unsigned int);
extern "C" void func_00490900(Font *,int,int);
static inline const char *c_str(String *s) {
 int len=*(int *)(s->p-16);
 if (!len) return D_006991B0;
 s->p[len]=0;
 return s->p;
}
extern "C" Font *func_002475D8(Style *s,void *rect) {
 Font *f=D_00624984;
 func_00490290(f,c_str(&s->text));
 float x=s->a34, y=s->a38;
 f->x=x; f->y=y; f->a70=s->a3c;
 f->shadow=func_00202EA8(s->shadow,1.0f);
 f->a6c=s->a14; f->a68=s->a18;
 f->color=func_00202EA8(s->color,1.0f);
 f->a2c=s->a28; f->a74=s->a50;
 float r[4];
 if(rect) {
 func_0025BAA0(rect,&r[0],&r[1],&r[2],&r[3]);
 func_00490700(f,(int)r[0],(int)r[1],(int)r[2],(int)r[3]);
 } else func_00490700(f,0,0,640,480);
 if(s->a20) { f->a64=func_00490740(f,s->a24); f->flag=1; }
 else func_00490900(f,0,0);
 return f;
}
