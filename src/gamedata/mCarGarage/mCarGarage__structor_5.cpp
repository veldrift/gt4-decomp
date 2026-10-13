typedef int s32;
struct VEntry { short delta, index; void (*fn)(void *, int); };
struct Obj { void *vtable; };
struct CarGarage { char pad[0x10]; s32 has; void *obj; };
extern "C" void func_00449D78(void *, int);
extern "C" void hObject__structor_2(void *, int);
extern "C" void free(void *);
extern "C" char mCarGarage__vtable[];
extern "C" void mCarGarage__structor_5(CarGarage *self, int flags) {
  *(char **)((char *)self + 4)=mCarGarage__vtable;
  if (self->has != 0) {
    Obj *obj=(Obj *)self->obj;
    if (obj != 0) {
      self->obj=0;
      self->has=0;
      VEntry *e=(VEntry *)((char *)obj->vtable+8);
      e->fn((char *)obj+e->delta,3);
    }
  }
  func_00449D78((char *)self+0x18,2);
  hObject__structor_2(self,0);
  if (flags & 1) return free(self);
}
