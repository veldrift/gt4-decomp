typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Sub {
    u8 flag;
    char pad0[0xB];
    f32 f;
    char pad1[4];
    char *vt;
};

struct Obj {
    char pad0[0x17BC];
    Sub a;
    char pad1[0x2D14 - 0x17BC - sizeof(Sub)];
    Sub b;
};

static inline void sub_call(Sub *s) {
    VEntry *e = (VEntry *)(s->vt + 0x28);
    e->fn((char *)s + e->delta);
}

extern "C" void func_0039FF78(Obj *self) {
    f32 one = 1.0f;
    Sub *p = &self->a;
    p->f = one;
    if (p->flag != 0) {
        sub_call(p);
    }
    p = &self->b;
    p->f = one;
    if (p->flag != 0) {
        sub_call(p);
    }
}
