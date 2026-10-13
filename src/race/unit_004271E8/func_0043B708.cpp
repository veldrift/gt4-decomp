typedef short s16;

struct Blk {
    char v[0x24];
};

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *self, Blk *b);
};

struct Src {
    VEntry *vt;
    Blk b;
};

extern "C" int func_0043B708(Src *self, Blk *dst)
{
    *dst = self->b;
    VEntry *e = (VEntry *)((char *)self->vt + 0x20);
    return e->fn((char *)self + e->delta, dst);
}
