/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block {
 char pad0[0x498]; unsigned char count; char pad1[7];
 void *items[43]; void *extra;
};
struct Context {
 char pad0[0x28]; void *handle; int *state; Block *block;
 char pad1[0x10]; int flag;
};
extern Context *D_006452D4;
extern "C" void func_004C8C38(Context *,void *);
extern "C" void func_004C3F90(void *,int);
extern "C" void func_004C3A48(Context *);
extern "C" int func_004BBCB8() {
 if (*D_006452D4->state!=101) return 0;
 {
  if (D_006452D4->block) {
   if (D_006452D4->block->extra)
    func_004C8C38(D_006452D4,D_006452D4->block->extra);
   for (int i=0;i<D_006452D4->block->count;i++) {
    void *p=D_006452D4->block->items[i];
    if (p) func_004C8C38(D_006452D4,p);
   }
   func_004C8C38(D_006452D4,D_006452D4->block);
  }
  D_006452D4->block=0;
  *D_006452D4->state=0;
  func_004C3F90(D_006452D4->handle,4);
  if (D_006452D4->flag == 0)
   func_004C3A48(D_006452D4);
 }
 return 0;
}
