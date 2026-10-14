typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct ObjInner {
    char pad[8];
    VEntry *vtbl;
};

struct ObjA {
    char pad[0x2880];
    struct ObjInner *unk2880;
};

struct ObjB : public ObjA {
    char pad2[0x3488 - sizeof(ObjA)];
    int unk3488;
};

extern "C" void func_003B4D80(struct ObjB *);

extern "C" void func_003B5E10(struct ObjB *arg0) {
    if (arg0->unk3488 == 0) {
        func_003B4D80(arg0);
    }
    {
        struct ObjInner *o = arg0->unk2880;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
        e->fn((char *)o + e->delta);
    }
    {
        struct ObjInner *o = arg0->unk2880;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x20);
        e->fn((char *)o + e->delta);
    }
}
