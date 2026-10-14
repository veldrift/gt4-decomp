struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { void *f0; VEntry *vtbl; };
struct Face { char pad[0xA0]; Obj *fA0; Obj *fA4; };
extern "C" void mTextFace__virtual_67(void);
extern "C" void func_001BF598(Obj *, void *, Face *);
extern "C" void func_001BE160(void);

static inline void vcall(Obj *o) {
    VEntry *e = o->vtbl + 50;
    e->fn((char *)o + e->delta);
}

extern "C" void mEyetoyFacePS2__virtual_67(Face *a) {
    Obj **p = &a->fA4;
    mTextFace__virtual_67();
    vcall(*p);
    func_001BF598(*p, (void *)func_001BE160, a);
    if (a->fA0)
        vcall(a->fA0);
}
