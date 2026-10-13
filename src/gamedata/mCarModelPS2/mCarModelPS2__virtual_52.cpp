typedef int s32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self);
};

struct Sub {
    char pad0[0xA8];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0xE8];
    Sub *sub;
    char pad1[0xEC];
    s32 f1d8;
};

extern "C" void func_00578B10(int);

extern "C" void func_001565F8(Obj *self) {
    Sub *s = self->sub;
    if (s) {
        VEntry *e = &s->vtbl[4];
        e->fn((char *)s + e->delta);
        if (self->f1d8) {
            do {
                func_00578B10(0x3E80);
            } while (self->f1d8 != 0);
        }
    }
}
