struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
struct Root { char pad[0x84]; Obj *race; };
extern "C" Root *D_00621CB4;

extern "C" int func_003DE800() {
    Obj *self = D_00621CB4->race;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x1E0);
    return entry->fn((char *)self + entry->delta);
}
