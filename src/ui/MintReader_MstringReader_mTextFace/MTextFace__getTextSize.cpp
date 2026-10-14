/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; char pad[12]; };
struct Floats { float a,b; char pad[8]; };
extern "C" void func_002434C8(Handle *,void *) throw();
extern "C" void func_00243470(Handle *,int) throw();
extern "C" void func_002452A8(void *,float *,float *);
extern "C" void func_002EFBF0(Handle *);
extern "C" void func_002F9360(Handle *,float);
extern "C" Handle *func_002EEEB0(Handle *,void *,Handle *);
extern "C" void func_00309378(Handle *,int);
extern "C" void func_002F7B68(Handle *,int);
extern "C" void func_002ED5C0(Handle *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MTextFace__getTextSize(Handle *dst,void *arg1) {
 Handle h;
 Floats f;
 Handle res,ret,x,y;
 Handle *pr,*pt;
 void *p;
 func_002434C8(&h,arg1);
 func_002452A8(h.p,&f.a,&f.b);
 pr = &res;
 func_002EFBF0(pr);
 p = pr->p;
 {
 Handle *pf = &x;
 pt = &ret;
 func_002F9360(pf,f.a);
 func_002EEEB0(pt,p,pf);
 func_00309378(pt,2);
 func_002F7B68(pf,2);
 }
 p = pr->p;
 {
 Handle *pf = &y;
 func_002F9360(pf,f.b);
 func_002EEEB0(pt,p,pf);
 func_00309378(pt,2);
 func_002F7B68(pf,2);
 }
 if (dst != pr) {
  void *q = pr->p;
  if (q) func_003285A8(q);
  if (dst->p) func_003285F8(dst->p);
  dst->p = q;
 }
 func_002ED5C0(pr,2);
 func_00243470(&h,2);
}
