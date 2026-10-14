/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Comparator { char *vt; void *fn; };
extern char D_0065B3E8[],D_0065B3C8[],hArrayCompare__vtable[];
extern "C" int func_002F03C8(void *,Comparator *);
extern "C" int func_002ED5C0(void *,int);
extern "C" void hArrayCompare__structor_0(void **array,void *fn,int descending) {
 Comparator c;
 if(descending) {
  void *p=*array;
  c.vt=D_0065B3E8; c.fn=fn;
  char *base=hArrayCompare__vtable;
  func_002F03C8(p,&c);
  c.vt=base;
 } else {
  void *p=*array;
  c.vt=D_0065B3C8; c.fn=fn;
  char *base=hArrayCompare__vtable;
  func_002F03C8(p,&c);
  c.vt=base;
 }
 func_002ED5C0(array,2);
}
