/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x680]; float block[4]; int value; };
extern "C" void func_003B0538(void *,float,void *,void *) throw();
extern "C" void func_0041B048(void *,void *,void *,float);
extern "C" int func_003B0940(Obj *out,Obj *a,Obj *b,float t) {
 func_0041B048(out,a,b,t);
 func_003B0538(out->block,t,a->block,b->block);
 if(t<0.5f) out->value=a->value;else out->value=b->value;
}
