extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
extern "C" void func_00528E38(void*);
struct Guard { void* p; Guard(void* q):p(q){func_00576788(q);} ~Guard(){func_005767C0(p);} };
struct Obj { char gap[0x958]; void* child; };
extern "C" void func_00503C48(Obj* self) { Guard guard(self); if(self->child){func_00528E38(self->child);self->child=0;} }
