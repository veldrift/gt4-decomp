/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *, int); };
struct Self { char pad0[12]; Entry *vt; int active; char pad1[0x48]; void *obj; char pad2[0x49c]; int state; };
extern "C" void RaceResultBase__startResultSequence(Self *);
extern "C" void func_004751D0(void *, int);
extern "C" void ResultArcade__startResultSequence(Self *self, int arg) {
 if(self->active) {
 self->state=1;
 RaceResultBase__startResultSequence(self);
 func_004751D0(self->obj,0);
 Entry *e=self->vt+11;
 e->fn((char *)self+e->delta,arg);
 }
}
