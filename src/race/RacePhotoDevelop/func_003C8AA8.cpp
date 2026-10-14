/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0x64]; char *vt; char pad1[0x23380-0x68]; int a; char pad2[0x2ef38-0x23384]; int b,c,d; };
extern "C" void func_0010AF10(int);
static inline void call(Obj *o, int off) { Entry *e=(Entry *)(o->vt+off); e->fn((char *)o+e->delta); }
extern "C" void func_003C8AA8(Obj *o, int x) {
 func_0010AF10(0);
 Entry *e=(Entry *)(o->vt+0x10);
 o->b=x; o->d=2; o->c=0; o->a=0;
 e->fn((char *)o+e->delta);
 call(o,0x20); call(o,0x2c0);
 o->b=0;
}
