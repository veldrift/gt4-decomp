/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { int f0; VEntry *vtbl; };
extern "C" void mTransition__panOut(Obj *, Obj *);
extern "C" void mUpdateContext__Sync(int);
extern "C" int mBlockTransition__initialize_blocks(Obj *) throw();
extern "C" void mBlockTransition__panOut(Obj *self, Obj *other) {
    mTransition__panOut(self, other);
    VEntry *e = (VEntry *)((char *)other->vtbl + 0x228);
    e->fn((char *)other + e->delta);
    mUpdateContext__Sync(1);
    mBlockTransition__initialize_blocks(self);
}
