typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x4];
    VEntry *vtbl;
};

extern "C" void func_00250990(Obj *);

extern "C" void func_00213AD8(Obj *self) {
    func_00250990(self);
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x1C8);

    e->fn((char *)self + e->delta);
}
