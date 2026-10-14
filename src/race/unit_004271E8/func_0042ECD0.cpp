/* compiler: ee-gcc2.96-nogcse */
extern "C" void *memcpy(void *, const void *, unsigned);
struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct C { VEntry *vtbl; };
extern "C" int func_0042ECD0(C *self, char *src) {
    memcpy((char *)self + 8, src, 0x2000);
    char *s2 = src + 0x2000;
    memcpy((char *)self + 0x2008, s2, 0x400);
    memcpy((char *)self + 0x2408, s2 + 0x400, 4);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
