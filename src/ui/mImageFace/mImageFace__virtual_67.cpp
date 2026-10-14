/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Holder { void *p; char pad[12]; };
struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };

struct Self {
    char pad0[0xB8];
    char *name;
    VObj *vobj;
    void *slot[2];
    s32 flags;
};

extern "C" void func_00210710(void *, int);
extern "C" void func_0025A7E0(void *, void *);
extern "C" void mTextFace__virtual_67(void *);
extern "C" void func_0026A118(void *, int);
extern "C" void func_0026A990(void *, void *, void *, s32, s32, s32);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline s32 vc58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void mImageFace__virtual_67(Self *self) {
    char **np = &self->name;
    mTextFace__virtual_67(self);
    if (((Rep *)*np)[-1].len == 0) return;
    if (self->vobj != 0 && vc58(self->vobj) != 0) return;
    Holder sp0;
    Holder h;
    Holder *ph = &h;
    void **dst = (void **)((char *)self + (((u32)self->flags >> 1) & 4) + 0xC0);
    func_0025A7E0(ph, self);
    func_0026A990(&sp0, ph->p, np, self->flags & 1, (self->flags >> 1) & 1, (self->flags >> 2) & 1);
    if (dst != &sp0.p) {
        void *nv = sp0.p;
        if (nv != 0) func_003285A8(nv);
        if (*dst != 0) func_003285F8(*dst);
        *dst = nv;
    }
    func_00210710(&sp0, 2);
    func_0026A118(ph, 2);
    self->vobj = *(VObj **)((char *)self + (((u32)self->flags >> 1) & 4) + 0xC0);
}
