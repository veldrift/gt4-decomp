/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Face { char pad[0xc8]; unsigned int unused:1; unsigned int flag:1; unsigned int rest:30; };
struct Obj { int pad; char *vtbl; };
struct VEntry { short delta, index; int (*fn)(void *); };
extern "C" void func_002A0D78(void *, void *) throw();
extern "C" void func_002A0D20(void *, int) throw();
static inline int getbool(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void MImageFace__set_from_disk(void *ret, void *ctx, int n, Obj **args) {
    if (n > 0) {
        Face *h[4];
        func_002A0D78(h, ctx);
        Face *f = h[0];
        int b = getbool(*args);
        f->flag = b != 0;
        func_002A0D20(h, 2);
    }
}
