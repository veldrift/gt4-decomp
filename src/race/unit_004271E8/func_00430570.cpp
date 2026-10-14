typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; char pad[4]; char data[0x108]; };
extern "C" s32 func_00430570(Obj *self, char *dst) {
    __builtin_memcpy(dst, (char *)self + 8, 0x108);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, dst);
}
