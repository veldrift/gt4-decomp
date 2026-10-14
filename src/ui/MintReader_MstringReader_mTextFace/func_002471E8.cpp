/* compiler: ee-gcc2.96-no-strict-aliasing */
struct String { char *p; };
struct Style {
 float color[4]; String text;
 int a14,a18,a1c,a20; unsigned int a24; int a28;
 float a2c,a30,a34,a38,a3c,shadow[4];
 int a50,a54,a58; float a5c,a60;
};
struct Font {
 char pad[0x24]; float x,y; int a2c;
 char pad30[0x14]; unsigned int color,shadow; int flag;
 int a50; char pad54[0x10]; int a64,a68,a6c; float a70; int a74;
};
extern Font *PDISTD__global_font_manager;
extern char D_006991B0[];
extern "C" void func_00490290(Font *,const char *);
extern "C" int func_00490740(Font *,unsigned int);
extern "C" void func_004908C0(Font *,float,float);
static inline const char *c_str(String *s) {
 int len=*(int *)(s->p-16);
 if (!len) return D_006991B0;
 s->p[len]=0;
 return s->p;
}
extern "C" void func_002471E8(Style *s) {
 Font *f=PDISTD__global_font_manager;
 func_00490290(f,c_str(&s->text));
 float x=s->a2c,y=s->a30;
 f->x=x; f->y=y; f->a70=s->a3c;
 f->a6c=s->a14; f->a68=s->a18;
 f->a50=s->a1c;
 if (s->a20 != 0) {
  f->a64=func_00490740(f,s->a24);
  f->flag=1;
 } else {
  func_004908C0(f,s->a5c,s->a60);
 }
 f->a2c=s->a28;
}
