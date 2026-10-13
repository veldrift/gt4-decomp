typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    s32 unk0;
    char *vtbl;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14;
};

extern "C" void *func_001C5898(s32 arg0);

extern "C" void mEyetoyPS2__virtual_49(Obj *self) {
    self->unk14 = func_001C5898(self->unk10);
    VEntry *e = (VEntry *)(self->vtbl + 0x2A8);
    e->fn((char *)self + e->delta);
}
