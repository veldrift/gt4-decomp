/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VE { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct Obj { char pad0[4]; char *vtbl; char pad8[8]; void *f10; };

extern "C" void func_002069E0(void *, void *, void *) throw();
extern "C" void func_0025C2D8(void *, void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline void vc(Obj *o, s32 off, void *a) {
    VE *e = (VE *)(o->vtbl + off);
    e->fn((char *)o + e->delta, a);
}

extern "C" void mPhotoMapWindow__virtual_101(Obj *self, Obj *a1, Obj *a2, Obj *a3) {
    vc(self, 0x2F8, a2);
    func_0025C2D8(a2, self);
    if (a1 != 0) {
        vc(a2, 0x2B0, a1->f10);
        vc(a2, 0x2C0, a1->f10);
        vc(a2, 0x2D0, a1);
    }
    func_003285A8(a3);
    func_002069E0(self, a2, a3);
    if (a1 != 0) {
        vc(a3, 0x2D8, a1);
        vc(a3, 0x2C8, a1->f10);
        vc(a3, 0x2B8, a1->f10);
    }
    func_003285F8(a3);
}
