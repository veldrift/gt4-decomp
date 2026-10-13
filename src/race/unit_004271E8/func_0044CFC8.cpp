typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct Obj {
    char *vtbl;
};

extern "C" s32 func_0044D020(void *arg0);

extern "C" s32 func_0044CFC8(Obj *self) {
    s32 s0 = func_0044D020(self);
    VEntry *e = (VEntry *)(self->vtbl + 0x18);
    s32 v = e->fn((char *)self + e->delta);
    return (s0 + v + 0x3F) & ~0x3F;
}
