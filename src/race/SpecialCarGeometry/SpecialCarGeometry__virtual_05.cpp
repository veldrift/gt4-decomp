typedef short s16;

struct VEntry_0038C468 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C468 {
    VEntry_0038C468 *vtbl;
};

extern "C" void SpecialCarGeometry__virtual_05(Obj_0038C468 *arg0) {
    Obj_0038C468 *self = arg0;
    VEntry_0038C468 *e = (VEntry_0038C468 *)((char *)self->vtbl + 0x18);

    e->fn((char *)self + e->delta);
}
