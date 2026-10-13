typedef int s32;
typedef short s16;

struct func_003B4FA0_arg0;
extern "C" void func_003B4FA0(struct func_003B4FA0_arg0 *arg0);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner {
    char pad[0x64];
    char *vtbl;
};

struct Leaf {
    void *f0;
};

struct Mid {
    char pad[0x8];
    Leaf *f8;
};

struct Obj {
    char pad[0x60];
    Mid *f60;
    char pad84[0x84 - 0x64];
    Inner *f84;
};

extern "C" void func_003C0B30(Obj *self) {
    Inner *a = self->f84;
    VEntry *e = (VEntry *)(a->vtbl + 0x218);
    e->fn((char *)a + e->delta);
    func_003B4FA0((struct func_003B4FA0_arg0 *)self->f60->f8->f0);
}
