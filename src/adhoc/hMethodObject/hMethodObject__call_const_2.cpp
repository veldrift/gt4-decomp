typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, void *, s32, s32);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

struct Self {
    char pad0[0x14];
    VObj *m14;
};

extern "C" void hMethodObject__call_const_2(Self *self, s32 a1, s32 a2, s32 a3) {
    VObj *o = self->m14;
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x80);
    e->fn((char *)o + e->delta, a1, (char *)self + 0x10, a2, a3);
}
