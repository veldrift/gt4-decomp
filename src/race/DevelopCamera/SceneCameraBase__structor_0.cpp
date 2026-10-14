struct Obj { char *vt; };
struct Entry { short delta,index; void (*fn)(char *,int); };
extern char D_0067A078[],SceneCameraBase__vtable[];
extern "C" void func_003FF940(void *,int);
extern "C" void func_00400720(void *,int);
extern "C" void func_004009B8(void *,int);
extern "C" void CameraBase__structor_1(void *,int);
extern "C" void func_005C1628(void *) throw();
static inline void destroy(Obj *p) {
 if(p) {
  Entry *e=(Entry *)(p->vt+8);
  e->fn((char *)p+e->delta,3);
 }
}
static inline Obj *load(char *p,int offset) { p+=offset; return *(Obj **)p; }
extern "C" void SceneCameraBase__structor_0(char *self,int flags) {
 char *b=self+8,*c=self+12,*d=self+16,*e=self+20;
 *(char **)self=D_0067A078;
 int i=0;
 do {
  destroy(load(b,i*0x19c+0x150));
  destroy(load(c,i*0x19c+0x150));
  destroy(load(d,i*0x19c+0x150));
  destroy(load(e,i*0x19c+0x150));
  destroy(load(b,i*0x19c+0x160));
  destroy(load(c,i*0x19c+0x160));
  destroy(load(d,i*0x19c+0x160));
  destroy(load(e,i*0x19c+0x160));
  destroy(load(b,i*0x19c+0x170));
  destroy(load(c,i*0x19c+0x170));
  destroy(load(d,i*0x19c+0x170));
  destroy(load(e,i*0x19c+0x170));
  destroy(load(b,i*0x19c+0x180));
  destroy(load(c,i*0x19c+0x180));
  func_005C1628(load(d,i*0x19c+0x180));
  i++;
 } while(i<6);
 func_003FF940(self+0xc04,2);
 func_00400720(self+0xbc0,2);
 func_004009B8(self+0xb80,2);
 *(char **)self=SceneCameraBase__vtable;
 CameraBase__structor_1(self,0);
 if(flags&1) return func_005C1628(self);
}
