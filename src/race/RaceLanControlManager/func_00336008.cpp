typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct VEntryR {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct Obj {
    char pad0[0x3C];
    char *vtbl;
    char pad1[0x40];
    s32 flag;
};

extern "C" s32 func_00336008(Obj *self) {
    if (self->flag == 0) return 0;
    VEntry *e1 = (VEntry *)(self->vtbl + 0x10);
    e1->fn((char *)self + e1->delta);
    VEntryR *e2 = (VEntryR *)(self->vtbl + 0x28);
    return e2->fn((char *)self + e2->delta);
}
