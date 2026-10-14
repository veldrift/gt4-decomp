/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { short delta,index; void (*fn)(void *,int,void *); };
struct S { int x; E *vt; };
extern "C" int func_00208308(S *) throw();
extern "C" int func_0025C418(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void mPhotoMapWindow__virtual_97(S *self,int arg1) {
 void *next=(void *)func_00208308(self);
 while(next) {
   void *p=next;
   next=(void *)func_0025C418(p);
   func_003285A8(p);
   E *e=&self->vt[103];
   e->fn((char *)self+e->delta,arg1,p);
   func_003285F8(p);
 }
}
