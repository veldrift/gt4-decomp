struct Obj { char pad[0xe0]; int count; };
extern "C" void func_001FE558(Obj*);
extern "C" void func_001FE510(Obj* self) {
 --self->count;
 if(self->count <= 0) {
  if(self->count < 0) self->count = 0;
  else func_001FE558(self);
 }
}
