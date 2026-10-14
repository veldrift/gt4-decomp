/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Target { char pad[0x10]; int id; };
struct Handle { Target *p; };
struct Obj { char pad[0x20]; int busy; char pad24[0xC0]; int disabled; char lock[4]; };
extern int D_00619278;
extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
extern "C" void func_0028EB38(void*,Handle*);
static inline int next_id() { return D_00619278++; }
extern "C" void func_00250CE0(Obj *p, Handle *h) {
 if(p->disabled==0) {
  if(p->busy==0) {
   Target *t=h->p;
   int old=next_id();
   t->id=old;
   void *lock=p->lock;
   func_00576788(lock);
   func_0028EB38((char*)p+0x10,h);
   func_005767C0(lock);
  }
 }
}
