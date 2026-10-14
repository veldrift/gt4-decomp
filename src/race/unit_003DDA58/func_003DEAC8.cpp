/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *, void *, void *); };
struct Obj { VEntry *vtbl; };
struct Header { int start; unsigned size; int x; int y; };
extern "C" char *Serialize__Base__getHeader(void *, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" char *func_003DEAC8(Obj *self, void *src, void *dest) {
    Header h;
    char *p = Serialize__Base__getHeader(&h, src);
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x30);
    if (e->fn((char *)self + e->delta, src, dest) == 2) return 0;
    unsigned n = h.size;
    if (n >= 0x61AC0) n = 0x61AC0;
    func_005A4724(dest, p, n);
    return p + h.size;
}
