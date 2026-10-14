/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct VEntry { short delta; short index; void (*fn)(void *, f32); };
struct Target { void *f0; VEntry *vtbl; };
struct Fade { char pad0[0x14]; Target *tgt; f32 f18; f32 f1C; f32 f20; };

static inline void vcall(Target *o, f32 v) {
    VEntry *e = o->vtbl + 58;
    e->fn((char *)o + e->delta, v);
}

extern "C" void mActor__initialize(void);

extern "C" void mFadeActor__initialize(Fade *a) {
    if (a->tgt) {
        mActor__initialize();
        f32 v = a->f1C;
        a->f18 = v;
        a->f20 = v;
        vcall(a->tgt, v);
    }
}
