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

extern "C" void mUpdateContext__virtual_66(Obj *);

extern "C" void mUpdateContextPS2__virtual_66(Obj *self) {
    mUpdateContext__virtual_66(self);
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x1C8);

    e->fn((char *)self + e->delta);
}
