/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int handle; char *data; };
extern "C" int func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" void func_00576100(void*);
extern "C" void func_00576140(void*);
extern "C" unsigned func_0057B440(void*,char*,unsigned);
extern "C" unsigned func_00504498(Obj *self,char *dst,unsigned n) {
 int sp[4];
 char *lock=self->data+0x38;
 char *ring=self->data+0x1c;
 sp[0]=self->handle;
 func_00576788(sp[0]);
 sp[1]=(int)lock;
 func_00576100(lock);
 unsigned result=func_0057B440(ring,dst,n);
 func_00576140(lock);
 func_005767C0(sp[0]);
 return result;
}
