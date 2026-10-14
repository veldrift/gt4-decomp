struct Entry { short delta,pad; void (*fn)(void*); };
struct Obj { int state; Entry* vt; };
extern "C" void func_003286B8(void*);
extern "C" void func_00328498(Obj* self) {self->state=-1;Entry*e=self->vt+2;e->fn((char*)self+e->delta);func_003286B8(self);}
