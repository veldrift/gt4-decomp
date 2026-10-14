/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0xC4]; void *c4; char pad2[0x34]; int fc; };
extern "C" void func_002C9098(S *,int) throw();
extern "C" void func_002C93C0(S *,int,int) throw();
extern "C" int mOptionMenu__virtual_78(S *self,int arg1) {
 if (self->c4) {
  if (self->fc==0) { func_002C9098(self,arg1); return 2; }
  else { func_002C93C0(self,arg1,0); return 2; }
 }
 return 2;
}
