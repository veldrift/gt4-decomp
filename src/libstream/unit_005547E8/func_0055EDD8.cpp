typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Server;

extern "C" void func_0055FB40(Server *self);

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Server {
    char pad0[0x3C];
    char *vt;
    char pad1[0x4C - 0x40];
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
};

extern "C" void func_0055EDD8(Server *arg0) {
    Server *self = arg0;

    func_0055FB40(self);
    {
        VEntry *e = (VEntry *)(self->vt + 0x28);
        if (e->fn((char *)self + e->delta) != 0) {
            VEntryV *e2 = (VEntryV *)(self->vt + 0x30);
            e2->fn((char *)self + e2->delta);
            self->f50 = self->f50 - 1;
            self->f58 = self->f58 + 1;
        }
    }
    if (self->f50 < self->f4C && (u32)self->f54 < (u32)self->f5C) {
        VEntryV *e3 = (VEntryV *)(self->vt + 0x38);
        e3->fn((char *)self + e3->delta);
        self->f50 = self->f50 + 1;
        self->f54 = self->f54 + 1;
    }
}
