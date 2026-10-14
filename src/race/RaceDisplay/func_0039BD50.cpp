/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char *vt; char pad4[0x1c]; int mode; };
static inline void invoke(Obj *self, int off) {
    VEntry *e = (VEntry *)(self->vt + off);
    e->fn((char *)self + e->delta);
}
extern "C" void func_0039BD50(Obj *self) {
    switch (self->mode) {
    case 0: invoke(self, 0xe8); break;
    case 1: invoke(self, 0xf8); break;
    case 4: invoke(self, 0x100); break;
    default: invoke(self, 0xf0); break;
    }
    invoke(self, 0x138);
}
