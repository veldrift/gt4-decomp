typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Inner {
    char pad[0x64];
    VEntry *vtbl;
};

struct Obj {
    char pad[0x84];
    Inner *unk84;
};

extern Obj *D_00621CB4;

static inline s32 vcall(Inner *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x1E0);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_003DE800(void) {
    vcall(D_00621CB4->unk84);
}
