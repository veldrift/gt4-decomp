typedef float f32;
struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct Obj { void *f0; VEntry *vtbl; };
struct SW {
    char pad0[0x14];
    void *f14;
    Obj *f18, *f1C, *f20;
    char pad24[4];
    f32 f28, f2C, f30, f34;
};
extern char D_0083B618[];
extern "C" void func_0025B538(void *, f32, f32, f32, f32);

static inline void vcall(Obj *o) {
    VEntry *e = o->vtbl + 60;
    e->fn((char *)o + e->delta, D_0083B618);
}

extern "C" void mSwitchActor__rewind(SW *a) {
    if (a->f14)
        func_0025B538(a->f14, a->f28, a->f2C, a->f30, a->f34);
    if (a->f18) vcall(a->f18);
    if (a->f1C) vcall(a->f1C);
    if (a->f20) vcall(a->f20);
}
