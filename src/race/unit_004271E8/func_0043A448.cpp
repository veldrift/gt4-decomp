typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char *vtbl;
};

extern "C" s32 func_0043A388(s32 arg0);

extern "C" s32 func_0043A448(Obj *self, s32 arg1) {
    VEntry *e = (VEntry *)(self->vtbl + 0x10);
    s32 r = e->fn((char *)self + e->delta);
    return arg1 + func_0043A388(r);
}
