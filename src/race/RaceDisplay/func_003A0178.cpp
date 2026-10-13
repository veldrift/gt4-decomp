typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Sub {
    unsigned char flag;
    char pad[0x13];
    char *vtbl;
};

struct Obj {
    char pad0[0x3C];
    unsigned char f3C;
    char pad1[0x23DC - 0x3D];
    Sub sub1;
    char pad2[0x291C - 0x23DC - sizeof(Sub)];
    Sub sub2;
};

static inline void dispatch(Sub *s) {
    VEntry *e = (VEntry *)(s->vtbl + 0x28);
    e->fn((char *)s + e->delta);
}

extern "C" void func_003A0178(Obj *self) {
    Sub *s = &self->sub1;
    if (self->f3C != 0) {
        if (s->flag != 0) {
            dispatch(s);
        }
        s = &self->sub2;
        if (s->flag != 0) {
            dispatch(s);
        }
    }
}
