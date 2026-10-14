typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x64];
    char *vtbl;
    char pad2[0xCD0 - 0x68];
    int active;
};

extern "C" void RaceBase__cleanupCamera(Obj *self) {
    if (self->active == 0) {
        VEntry *e = (VEntry *)(self->vtbl + 0x198);
        e->fn((char *)self + e->delta);
    }
}
