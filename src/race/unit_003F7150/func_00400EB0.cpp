struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; };

extern "C" int func_00400EB0(Obj *arg0, int unused, void *arg2) {
    Obj *self = arg0;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x138);
    entry->fn((char *)self + entry->delta, arg2);
    return 1;
}
