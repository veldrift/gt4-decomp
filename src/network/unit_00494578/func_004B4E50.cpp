/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Range { int x; short begin,end; };
extern "C" Range *func_004B5CC0(void *);
extern "C" void func_004B49B8(void *, Range *, u16 *, int) throw();
extern "C" void func_004B5E00(void *, Range *, u16 *, int);
extern "C" int func_004B8F60(u16 *, int);
extern "C" int func_004B93E0(const u16 *);
static inline int length(const u16 *s) { int i=0; while (s[i]) i++; return i; }
extern "C" void func_004B4E50(void *p) {
 u16 buf[256];
 u16 out[8];
 Range *r=func_004B5CC0(p);
 if (r->end-r->begin>0) {
 func_004B49B8(p,r,buf,256);
 int i=length(buf);
 if (func_004B8F60(out,func_004B93E0(buf+i-1))) func_004B5E00(p,r,out,1);
 }
}
