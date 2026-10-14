/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a, b; };
struct Obj { char pad0[12]; int c, x, one, zero; char pad1[0x240]; int a25c, a260, a264, a268; Pair pair; int a274,a278,a27c,a280,a284,a288,a28c,a290,a294; void *vt; };
extern char EyeToyPS2__vtable[];
extern "C" void func_005D0A10(void *, void *);
extern "C" void func_001C4FB8(void *);
extern "C" void EyeToyPS2__structor_0(Obj *o, int x) {
 o->vt = EyeToyPS2__vtable;
 func_005D0A10(o, o);
 o->c = 0;
 o->x = x;
 o->one = 1;
 o->zero = 0;
 o->a25c = 0;
 o->a260 = 0;
 o->a264 = 0;
 o->a268 = 0;
 Pair *p = &o->pair;
 p->a = 0;
 p->b = 0;
 o->a274 = 0;
 o->a278 = 0;
 o->a27c = 0;
 o->a280 = 0;
 o->a284 = -1;
 o->a288 = 0;
 o->a28c = 0;
 o->a290 = 0;
 o->a294 = 0;
 return func_001C4FB8(o);
}
