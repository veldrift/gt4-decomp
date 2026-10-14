extern "C" void *memcpy(void *, const void *, unsigned);
struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct C { VEntry *vtbl; };
extern "C" int func_0042EB20(C *self, char *dst) {
    char *s = (char *)self;
    memcpy(dst, s + 8, 0x2000);
    char *d2 = dst + 0x2000;
    memcpy(d2, s + 0x2008, 0x400);
    memcpy(d2 + 0x400, s + 0x2408, 4);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, dst);
}
