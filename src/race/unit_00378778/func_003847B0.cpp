struct VEntry { short delta; short index; void (*fn)(void *, int *); };
struct Obj { VEntry *vtbl; };

extern "C" void func_003847B0(Obj *arg0, int *arg1) {
    Obj *self = arg0;
    VEntry *entry = (VEntry *)((char *)self->vtbl + 0x68);
    entry->fn((char *)self + entry->delta, arg1);
}
