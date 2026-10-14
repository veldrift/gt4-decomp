/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
struct VEntry { s16 delta; s16 index; void *(*fn)(void *); };
struct Obj { VEntry *vtbl; };
extern "C" void *RacePhotoModeCameraManager__virtual_30(struct Obj *self) {
    VEntry *e = &self->vtbl[61];
    void *r = e->fn((char *)self + e->delta);
    if (r == 0)
        return (char *)self + 0xB40;
    return (char *)r + 0x100;
}
