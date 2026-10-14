/* compiler: ee-gcc2.96-no-strict-aliasing */
struct rbuf__vtable { void *pool; int a; int *ap; int b; int *bp; int p14,p18; int data; unsigned size,mask; int p28,p2c; unsigned capacity; int p34,p38,p3c; rbuf__vtable(int) __asm__("func_00554668"); virtual ~rbuf__vtable(); };
extern "C" void *exception__structor_0(int, unsigned);
extern "C" void fpool__structor_0(void *, int, int);
extern "C" int func_00575E60(int, int);
rbuf__vtable::rbuf__vtable(int n) {
 rbuf__vtable *self=this;
 n += 15;
 unsigned size = n & ~15;
 size *= 2;
 unsigned power=1;
 if(size<power) size=1;
 else { do { power*=2; } while(size>=power); size=power; }
 void *pool=exception__structor_0(32,power);
 fpool__structor_0(pool,8,4);
 self->pool=pool;
 *(int *)((char *)self+4)=0; self->ap=&self->a; *(int *)((char *)self+12)=0;
 self->bp=&self->b;
 self->data=func_00575E60(64,size);
 self->size=size; self->capacity=size; self->mask=size-1;
 self->p28=0; self->p2c=0; self->p34=0; self->p3c=0; self->p38=0;
}
