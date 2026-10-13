typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    s32 unk0;
    char pad[0x7D8];
    char *vtbl;
};

extern "C" void func_003B0ED8(Obj *);
extern "C" void func_00454410(s32);
extern "C" void func_003B0C80(Obj *);
extern "C" void func_003B04F0(void *);
extern "C" void func_003B0D18(Obj *);
extern "C" void func_003B0F00(Obj *);

extern "C" void func_003B0F58(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x20);

    e->fn((char *)self + e->delta);
    func_003B0ED8(self);
    if (self->unk0 != 0) {
        func_00454410(self->unk0);
        func_003B0C80(self);
        func_003B04F0((char *)self + 0x690);
        func_003B0D18(self);
        func_003B0F00(self);
    }
}
