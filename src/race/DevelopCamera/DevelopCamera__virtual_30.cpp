typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; void *(*fn)(void *, s32); };
struct Obj {
    VEntry *vtbl;
    char pad[0x9B8];
    s32 arg;
};
extern "C" void *DevelopCamera__virtual_30(struct Obj *self) {
    VEntry *e = &self->vtbl[27];
    void *r = e->fn((char *)self + e->delta, self->arg);
    if (r == 0)
        return (char *)self + 0xB40;
    return (char *)r + 0x100;
}
