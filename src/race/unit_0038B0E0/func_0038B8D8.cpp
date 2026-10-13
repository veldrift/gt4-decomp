typedef short s16;

struct VEntry1 {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct VEntry3 {
    s16 delta;
    s16 index;
    void (*fn)(void *self, int a, int b);
};

struct Obj {
    char pad0[0xC];
    char *vtbl;
};

struct Self {
    char pad0[0x6C];
    int f6C;
    char pad1[0xCC8 - 0x70];
    int fCC8;
    char pad2[0xCD0 - 0xCCC];
    int w;
    char pad3[0xE41C - 0xCD4];
    Obj *slot;
};

extern "C" void func_0038B8D8(Self *self, Obj *val) {
    if (self->w == 0) {
        Obj *old = self->slot;
        if (old) {
            VEntry1 *e1 = (VEntry1 *)(old->vtbl + 0x18);
            e1->fn((char *)old + e1->delta);
        }
        self->slot = val;
        if (val) {
            VEntry3 *e2 = (VEntry3 *)(val->vtbl + 0x10);
            e2->fn((char *)val + e2->delta, self->f6C, self->fCC8);
        }
    }
}
