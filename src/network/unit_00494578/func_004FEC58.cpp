/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int words[43]; };
struct Obj { char pad[0x5a8]; Block *buffer; char pad5ac[0xa44-0x5ac]; Block source; };
extern "C" int func_004F0C88(Obj *);
extern "C" int func_004F0CD0(Obj *,int);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_004FEC58(Obj *self) {
 if(func_004F0C88(self)) {
  func_005A48D8(self->buffer,0,0xc4);
  *self->buffer=self->source;
  return func_004F0CD0(self,0x50);
 }
 return 0;
}
