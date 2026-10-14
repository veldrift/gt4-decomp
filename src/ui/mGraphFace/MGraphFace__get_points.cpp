/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int count; char *vt; char pad[0xb8]; int n; float xy[2]; };
struct H { Obj *p; char pad[12]; };
struct Entry { short delta,idx; void *fn; };
extern "C" int mBlob__GetClassID();
extern "C" int hArray__GetClassID();
extern "C" int hObject__isInstanceOf(Obj *,int);
extern "C" void func_0029E848(H *,H *) throw();
extern "C" void func_0029E7F0(H *,int) throw();
extern "C" void func_002ED618(H *,H *);
extern "C" void func_002ED5C0(H *,int);
extern "C" int hArray__size(Obj *);
extern "C" void func_0029F790(Obj *,int);
extern "C" void func_0029F798(Obj *,void *);
extern "C" void *func_001FFF88(H *,H *);
extern "C" void func_001FFF30(H *,int);
extern "C" void func_002EFBF0(H *);
extern "C" void func_002F9360(H *,float);
extern "C" H *func_002EEEB0(H *,Obj *,H *);
extern "C" void func_00309378(H *,int);
extern "C" void func_002F7B68(H *,int);
extern "C" void func_003285A8(Obj *);
extern "C" void func_003285F8(Obj *);
static inline H *index(Obj *o,int i) {
 Entry *e=(Entry *)(o->vt+0x70);
 return ((H *(*)(void *,int))e->fn)((char *)o+e->delta,i);
}
static inline float value(Obj *o) {
 Entry *e=(Entry *)(o->vt+0x60);
 return ((float (*)(void *))e->fn)((char *)o+e->delta);
}
static inline void assign(H *d,H *s) {
 if(d!=s) { Obj *p=s->p; if(p)func_003285A8(p); if(d->p)func_003285F8(d->p); d->p=p; }
}
extern "C" void MGraphFace__get_points(H *out,H *ctx,int argc,H *args) {
 H self, a, row, b, result, x, y;
 func_0029E848(&self,ctx);
 if(argc>0) {
  Obj *o=args->p;
  if(hObject__isInstanceOf(o,hArray__GetClassID())) {
   float *dst=self.p->xy;
   H *pa=&a;
   func_002ED618(pa,args);
   int i=0;
   int n=hArray__size(pa->p);
   func_0029F790(self.p,n);
   for(;i<n;) {
    H *pr=&row;
    func_002ED618(pr,index(pa->p,i++));
    float vx=value(index(pr->p,0)->p);
    float vy=value(index(pr->p,1)->p);
    dst[0]=vx;
    dst[1]=vy;
    dst+=2;
    func_002ED5C0(pr,2);
   }
   func_002ED5C0(pa,2);
  } else {
   Obj *o=args->p;
   if(hObject__isInstanceOf(o,mBlob__GetClassID())) {
    H *pa=&a;
    func_001FFF88(pa,args);
    void *data=*(void **)((char *)pa->p+0x10);
    func_001FFF30(pa,2);
    if(data)func_0029F798(self.p,data);
   }
  }
 } else {
  int n=self.p->n;
  float *src=self.p->xy;
  H *pa=&a;
  func_002EFBF0(pa);
  for(int i=0;i<n;i++) {
   H *pb=&b;
   H *res=&result;
   H *px=&x;
   H *py=&y;
   func_002EFBF0(pb);
   Obj *o=pb->p;
   func_002F9360(px,src[0]);
   func_002EEEB0(res,o,px);
   func_00309378(res,2);
   func_002F7B68(px,2);
   o=pb->p;
   float vy=src[1]; src+=2;
   func_002F9360(py,vy);
   func_002EEEB0(res,o,py);
   func_00309378(res,2);
   func_002F7B68(py,2);
   func_002EEEB0(res,pa->p,pb);
   func_00309378(res,2);
   func_002ED5C0(pb,2);
  }
  assign(out,pa);
  func_002ED5C0(pa,2);
 }
 func_0029E7F0(&self,2);
}
