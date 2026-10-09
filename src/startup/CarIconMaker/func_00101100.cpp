struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" void func_00101100(Obj *self) {
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x70);
    entry->fn((char *)self + entry->delta, 0x1.111110p-6f);
}
