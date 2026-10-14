/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; int *(*fn)(void *); };
struct Obj { char pad[0x4C]; VEntry *vt; };
extern "C" int func_001CCAA0(Obj *self) {
    int n = 0;
    VEntry *e = self->vt + 17;
    int *p = e->fn((char *)self + e->delta);
    while (*p++ != 0) n++;
    return n;
}
