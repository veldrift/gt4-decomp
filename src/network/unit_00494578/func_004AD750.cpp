typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0xA0];
    s32 flag;
    char *vtbl;
};

extern "C" void func_004AD750(Obj *self) {
    VEntry *e1 = (VEntry *)(self->vtbl + 0x10);
    e1->fn((char *)self + e1->delta);
    self->flag = 0;
    VEntry *e2 = (VEntry *)(self->vtbl + 0x28);
    e2->fn((char *)self + e2->delta);
}
