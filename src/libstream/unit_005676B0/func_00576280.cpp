typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char *vtbl;
    char pad[0x104 - 4];
    s32 f104;
    s32 f108;
    s32 f10C;
};

extern "C" int func_005AE268(int mode, int a, int b);

extern "C" void func_00576280(Obj *self) {
    if (self->f108 != 10 && self->f104 != 0) {
        VEntry *e = (VEntry *)(self->vtbl + 0x18);
        e->fn((char *)self + e->delta, 10);
    }
    if (self->f10C != 0) {
        func_005AE268(1, (int)((char *)self + 4), self->f10C);
        self->f10C = 0;
    }
}
