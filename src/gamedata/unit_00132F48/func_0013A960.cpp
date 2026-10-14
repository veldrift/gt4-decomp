struct Entry { short delta,pad; int (*fn)(void*); };
struct Child { int field; Entry* vt; };
struct Obj { char pad[0x2a4]; Child* child; };
extern "C" int func_0013A960(Obj* self) {
 Child* c=self->child;
 if(c){Entry* e=c->vt+55;return e->fn((char*)c+e->delta);}
 return -1;
}
