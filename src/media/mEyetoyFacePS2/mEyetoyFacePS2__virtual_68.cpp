/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { void *f0; VEntry *vtbl; };
struct Handle { Obj *p; Obj *get() { return p; } };
struct Face { char pad[0xA0]; Obj *fA0; Handle fA4; };
extern "C" void mTextFace__virtual_68(void);
extern "C" void func_001BF598(Obj *, void *, void *);
static inline void vcall(Obj *o) {
    VEntry *e = o->vtbl + 51;
    e->fn((char *)o + e->delta);
}
extern "C" void mEyetoyFacePS2__virtual_68(Face *a) {
    mTextFace__virtual_68();
    if (a->fA0) vcall(a->fA0);
    Handle *p = &a->fA4;
    func_001BF598(p->get(), 0, 0);
    vcall(p->get());
}
