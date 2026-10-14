/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0xac/4]; };
struct Obj { char pad[0x5a8]; Block *dst; char pad2[0xa44-0x5ac]; Block src; int a,b; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_004FDF90(Obj *o,int a,int b) {
 if (func_004F0C88(o)) {
  func_005A48D8(o->dst,0,0xc4);
  *o->dst=o->src;
  o->a=a;
  o->b=b;
  return func_004F0CD0(o,0x4c);
 }
}
