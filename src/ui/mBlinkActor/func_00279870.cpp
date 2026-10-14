/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj {
    int f0;
    char *vtbl;
    char pad8[0x28];
    float f30, f34, f38;
};
extern "C" void func_00279870(Obj *a, float f) {
    f *= 60.0f;
    a->f30 = (a->f34 - a->f38) / f;
    VEntry *e = (VEntry *)(a->vtbl + 0x198);
    e->fn((char *)a + e->delta);
}
