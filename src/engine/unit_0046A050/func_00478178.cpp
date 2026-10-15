/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val { int type; int value; bool isString() const {return (unsigned)(type-3)<2;} };
extern "C" Val *func_00476768(Val *,const Val *) throw();
extern "C" void func_004768C0(Val *) throw();
extern "C" const char *strobe__Any__toString(Val *) throw();
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" bool func_00478250(const Val *,const Val *);
static inline bool isOne(int x) { return x == 1; }
extern "C" bool func_00478178(const Val *a,const Val *b) {
 int at=a->type;
 if ((unsigned)(at-3)<2 || b->isString()) {
  Val ta,tb;
  func_00476768(&ta,a);
  func_00476768(&tb,b);
  int r=func_0057F238(strobe__Any__toString(&ta),strobe__Any__toString(&tb))==0;
  func_004768C0(&tb);
  func_004768C0(&ta);
  return r;
 }
 int bt=b->type;
 if ((isOne(at) && isOne(bt)) || (at==0 && bt==0)) return 1;
 return func_00478250(a,b);
}
