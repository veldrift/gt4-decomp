/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
struct Root { char pad[0x84]; Obj *race; };
extern "C" Root *D_00621CB4;
extern "C" int *func_0044D050();
extern "C" void *func_003DE6B0() {
    int *p = func_0044D050();
    Obj *self = D_00621CB4->race;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x1B8);
    entry->fn((char *)self + entry->delta, p);
    return (char *)p + *p;
}
