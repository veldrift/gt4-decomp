typedef int s32;

struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct Target {
    VEntry *vtbl;
};

struct Obj {
    VEntry *vtbl;
    char pad4[0x9BC - 4];
    s32 unk9BC;
    char pad9C0[0xA08 - 0x9C0];
    float unkA08;
};

extern "C" float DevelopCamera__virtual_19(Obj *self)
{
    VEntry *e = &self->vtbl[27];
    Target *target = ((Target *(*)(void *, s32))e->fn)((char *)self + e->delta, self->unk9BC);
    if (target == 0)
        return self->unkA08;
    VEntry *f = &target->vtbl[19];
    return ((float (*)(void *, void *))f->fn)((char *)target + f->delta, (char *)self + 0x9C0);
}
