struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };

extern "C" void RacePS2Base__virtual_16(Obj *arg0) {
    Obj *self = arg0;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x3C8);
    entry->fn((char *)self + entry->delta);
}
