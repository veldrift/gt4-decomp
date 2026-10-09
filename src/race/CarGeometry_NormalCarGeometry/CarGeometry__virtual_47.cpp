typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    ObjInner *unk1C;
};

extern "C" int CarGeometry__virtual_47(Obj *arg0) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = (VEntry *)((char *)a1->vtbl + 0x180);

    return e->fn((char *)a1 + e->delta);
}
