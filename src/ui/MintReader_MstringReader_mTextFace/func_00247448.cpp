/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Face {
 float color[4]; char *text; int i14,i18,i1c,i20,i24,i28;
 float f2c,f30,f34,f38,f3c,shadow[4]; int i50,i54,i58; float f5c,f60;
};
struct Renderer {
 char pad[0x24]; float f24,f28; int i2c; char pad30[0x14];
 unsigned int i44,i48; int i4c; char pad50[0x14]; int i64,i68,i6c; float f70; int i74;
};
extern Renderer *D_00624984;
extern char D_006991B0[];
extern "C" void func_00490290(Renderer *, const char *);
extern "C" unsigned int func_00202EA8(float *, float);
extern "C" void func_0025BAA0(void *, float *, float *, float *, float *);
extern "C" void func_00490700(Renderer *, int,int,int,int);
extern "C" int func_00490740(Renderer *, unsigned int);
extern "C" void func_00490900(Renderer *, int,int);
static inline const char *text(Face *o) {
 char **s = &o->text;
 char *p = *s;
 int n = *(int *)(p-16);
 if (n == 0) return D_006991B0;
 p[n] = 0;
 return *s;
}
extern "C" Renderer *func_00247448(Face *o, void *ctx) {
 Renderer *r = D_00624984;
 func_00490290(r, text(o));
 float sx = o->f2c;
 float sy = o->f30;
 r->f24 = sx;
 r->f28 = sy;
 r->f70 = o->f3c;
 r->i48 = func_00202EA8(o->shadow, 1.0f);
 r->i6c = o->i14;
 r->i68 = o->i18;
 r->i44 = func_00202EA8(o->color, 1.0f);
 r->i2c = o->i28;
 r->i74 = o->i50;
 if (ctx != 0) {
  float x,y,z,w;
  func_0025BAA0(ctx,&x,&y,&z,&w);
  func_00490700(r,(int)x,(int)y,(int)z,(int)w);
 } else {
  func_00490700(r,0,0,640,480);
 }
 if (o->i20 != 0) {
  r->i64 = func_00490740(r,o->i24);
  r->i4c = 1;
 } else {
  func_00490900(r,0,0);
 }
 return r;
}
