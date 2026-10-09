struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };

extern "C" void RaceNetBattle__virtual_76(Obj *arg0) {
    Obj *self = arg0;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x4B8);
    entry->fn((char *)self + entry->delta);
}
