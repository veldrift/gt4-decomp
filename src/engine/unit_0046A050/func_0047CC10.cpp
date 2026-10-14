/* compiler: ee-gcc2.96-stl */
extern "C" void free(void *) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
typedef unsigned int u32;
struct Val;
extern "C" int func_00476768(Val *, const Val *) throw();
extern "C" void func_004768C0(Val *);
extern "C" void func_00476A98(Val *, const char *) throw();
extern "C" void func_00476AE8(Val *, int);
extern "C" char *strobe__Any__toString(Val *) throw();
extern "C" float func_00477460(Val *) throw();
struct Stack { int a,b; Val *end; };
extern "C" void func_00480F78(Stack *);
extern "C" void func_00480FA0(Stack *, int);
extern "C" void free(void *) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005A47D4(void *, const void *, u32) throw();
extern "C" void *func_005A6AB0(void *, const void *, int) throw();
extern char D_006ADD30[], D_006ADD38[];
extern void *D_00659E2C[];
struct Val {
 int type, value;
 Val():type(1) {}
 Val(const Val &v) { func_00476768(this, &v); }
 ~Val() { func_004768C0(this); }
};
typedef vector<char> Vec;
template <> void Vec::insert(char *, unsigned int, const char &) __asm__("func_00607048");
extern "C" Val func_0047CC10(Val *self, int count, Stack *stack) {
 if(count==2) {
   Val result;
   const char *str=strobe__Any__toString(self);
   int start=(int)func_00477460(stack->end-1);
   func_00480F78(stack);
   int len=(int)func_00477460(stack->end-1);
   func_00480F78(stack);
   if(start<0) return result;
   int total=func_0057F260(str);
   if(start>total) {func_00476AE8(&result,(int)D_006ADD30); return result;}
   if(start+len>=total) {func_00476A98(&result,str+start); return result;}
   char buf[256];
   Vec v;
   char *p=buf;
   if(len>=255) {v.resize(len+1); p=v.begin();}
   func_005A6AB0(p,str+start,len);
   p[len]=0;
   func_00476A98(&result,p);
   return result;
 }
 func_0057D9C0(D_006ADD38);
 func_00480FA0(stack,count);
 return Val();
}
