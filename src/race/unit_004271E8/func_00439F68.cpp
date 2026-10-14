typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; char data[0x74]; };
extern "C" s32 func_00439F68(Obj *self, char *src) {
    __builtin_memcpy((char *)self + 4, src, 0x74);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
