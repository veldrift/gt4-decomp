/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { short delta,index; void (*fn)(void *,void *); };
struct S { int x; E *vt; char pad[8]; void *p10; };
extern "C" void func_00206888(S *, S *,int) throw();
extern "C" void func_0025C2D8(S *, S *);
extern "C" void mPhotoMapWindow__virtual_100(S *self,S *arg1,S *child,int arg3) {
 E *e=&self->vt[95];
 e->fn((char *)self+e->delta,child);
 func_0025C2D8(child,self);
 if(arg1) {
  E *e2=&child->vt[86];
  e2->fn((char *)child+e2->delta,arg1->p10);
  E *e3=&child->vt[88];
  e3->fn((char *)child+e3->delta,arg1->p10);
  E *e4=&child->vt[90];
  e4->fn((char *)child+e4->delta,arg1);
 }
 func_00206888(self,child,arg3);
}
