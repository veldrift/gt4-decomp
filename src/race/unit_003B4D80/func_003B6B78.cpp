/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; char *vt; };
struct Self { char pad[0x2880]; Obj *obj; };
struct E1 { short delta,index; int (*fn)(void *); };
struct E2 { short delta,index; void (*fn)(void *,int,int); };
extern "C" int func_003D6F30(void *);
static inline int check(Obj *o) {
 E1 *e = (E1 *)(o->vt+0x148);
 return e->fn((char *)o+e->delta);
}
static inline void send(Obj *o,int a,int b) {
 E2 *e = (E2 *)(o->vt+0x150);
 e->fn((char *)o+e->delta,a,b);
}
extern "C" int func_003B6B78(Self *self,int arg) {
 int r=func_003D6F30((char *)self+0x2890);
 if (r != 0) {
  if(check(self->obj)) {
   if(arg) send(self->obj,0,arg);
   return r;
  }
 }
 return 0;
}
