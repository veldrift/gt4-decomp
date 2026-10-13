typedef short s16;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Sub {
    u8 flag;
    char pad[0x13];
    char *vt;
};

struct Obj {
    char pad0[0x3A];
    u8 f3A;
    char pad1[0x1300 - 0x3B];
    Sub a;
    char pad2[0x1684 - 0x1300 - sizeof(Sub)];
    Sub b;
};

static inline void sub_call(Sub *s) {
    VEntry *e = (VEntry *)(s->vt + 0x28);
    e->fn((char *)s + e->delta);
}

extern "C" void func_0039FD30(Obj *self) {
    if (self->f3A == 0) {
        Sub *p = &self->a;
        if (p->flag != 0) {
            sub_call(p);
        }
        p = &self->b;
        if (p->flag != 0) {
            sub_call(p);
        }
    }
}
