/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0xac/4]; };
struct Data { Block block; int a,b; };
struct Obj { char pad[0x5a8]; Data *dst; char pad2[0xa44-0x5ac]; Block src; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_004FD9B0(Obj *o,int a,int b) {
 if (func_004F0C88(o)) {
  func_005A48D8(o->dst,0,0xcc);
  Data *dst=o->dst;
  dst->block=o->src;
  dst->a=a;
  dst->b=b;
  return func_004F0CD0(o,0x4a);
 }
}
