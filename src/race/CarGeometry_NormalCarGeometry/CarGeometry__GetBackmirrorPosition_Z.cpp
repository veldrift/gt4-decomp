typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    float (*fn)(void *, float);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    ObjInner *implementation;
};

static inline float query(Obj *obj, int offset, float value) {
    ObjInner *inner = obj->implementation;
    VEntry *entry = (VEntry *)((char *)inner->vtbl + offset);
    return entry->fn((char *)inner + entry->delta, value);
}

extern "C" float CarGeometry__GetBackmirrorPosition_Z(Obj *arg0, float value) {
    if (query(arg0, 0xC8, value) == 0x0p0f &&
        query(arg0, 0xD0, value) == 0x0p0f &&
        query(arg0, 0xD8, value) == 0x0p0f) {
        return -0x1.8p1f;
    }
    return query(arg0, 0xD8, value);
}
