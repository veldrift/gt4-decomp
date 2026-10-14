struct VE { short delta, index; int (*fn)(void *); };
struct VF { short delta, index; float (*fn)(void *); };
struct Value { int first; char *vt; };
struct Config { int n; float f[10]; };
struct Data { char pad[0x24]; Config c; };
struct Input { char pad[0x10]; Data *data; };
struct Handle { void *p; char pad[12]; };
extern "C" void func_0017FAD0(Handle *, int) throw();
extern "C" void func_0017FB28(Handle *, void *) throw();
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED618(Handle *, void *);
extern "C" void *func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_002EFBF0(Handle *);
extern "C" Value **HArray__operator_index(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002F7B68(Handle *, int);
extern "C" void func_002F9360(Handle *, float);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline int geti(Handle *h, int i) {
 Value *p = *HArray__operator_index(h,i); VE *v = (VE *)(p->vt+0x58);
 return v->fn((char *)p+v->delta);
}
static inline float getf(Handle *h, int i) {
 Value *p = *HArray__operator_index(h,i); VF *v = (VF *)(p->vt+0x60);
 return v->fn((char *)p+v->delta);
}
static inline void store(Handle *p, const Config *v) {
 ((Input *)p->p)->data->c = *v; func_0017FAD0(p,2);
}
extern "C" void MOption__get_physical_monitor_size(void **ret, void *input, int n, void *arg) {
 union { Config c; struct { Handle a,b,c; } h; } u;
 Handle b,c;
 if(n>0) {
  func_002ED618(&b,arg);
  u.c.n=geti(&b,0);
  u.c.f[0]=getf(&b,1);
  u.c.f[1]=getf(&b,2);
  u.c.f[2]=getf(&b,3);
  u.c.f[3]=getf(&b,4);
  u.c.f[4]=getf(&b,5);
  u.c.f[5]=getf(&b,6);
  u.c.f[6]=getf(&b,7);
  u.c.f[7]=getf(&b,8);
  u.c.f[8]=getf(&b,9);
  u.c.f[9]=getf(&b,10);
  func_0017FB28(&c,input);
  store(&c,&u.c);
  func_002ED5C0(&b,2);
  return;
 }
 func_0017FB28(&u.h.a,input);
 Data *data=((Input *)u.h.a.p)->data;
 func_0017FAD0(&u.h.a,2);
 func_002EFBF0(&u.h.a);
 Config *v=&data->c;
 Handle *dest=&u.h.b;
 Handle *temp=&u.h.c;
 { void *p=u.h.a.p;
 func_002FE278(temp,v->n);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002FC870(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[0]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[1]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[2]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[3]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[4]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,v->f[5]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,data->c.f[6]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,data->c.f[7]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,data->c.f[8]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 { void *p=u.h.a.p;
 func_002F9360(temp,data->c.f[9]);
 func_002EEEB0(dest,p,temp);
 func_00309378(dest,2);
 func_002F7B68(temp,2);
 }
 if(ret != &u.h.a.p) {
  void *p=u.h.a.p;
  if(p) func_003285A8(p);
  if(*ret) func_003285F8(*ret);
  *ret=p;
 }
 func_002ED5C0(&u.h.a,2);
}
