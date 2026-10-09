struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct Inner { char pad[0x64]; VEntry *vtbl; };
extern "C" void CarIconMaker__virtual_14(Inner *arg0, void *arg1) {
    Inner *self = arg0;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x80);
    entry->fn((char *)self + entry->delta, arg1);
}
