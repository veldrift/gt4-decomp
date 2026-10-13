struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct VObj {
    char pad0[0x10140];
    char *vtbl;
};

extern "C" int func_003F6320(VObj *o)
{
    VEntry *e = (VEntry *)(o->vtbl + 0x128);
    int a = e->fn((char *)o + e->delta);
    VEntry *f = (VEntry *)(o->vtbl + 0x150);
    int b = f->fn((char *)o + f->delta);
    if (a == 0)
        a = 1;
    return a * b < 0x11;
}
