typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; char pad[4]; char data[0xB6C - 8 + 0x144]; };
extern "C" s32 func_00430120(Obj *self, char *src) {
    __builtin_memcpy((char *)self + 0xB6C, src, 0x144);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
