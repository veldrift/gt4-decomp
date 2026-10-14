/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(void *, s32);
};
struct VTab {
    char pad[0x1D8];
    VEnt e;
};
struct Target {
    char pad0[4];
    VTab *vt;
};
struct Arg1 {
    char pad0[0x10];
    Target *tgt;
    char pad1[0x6E8 - 0x14];
    s32 f6E8;
};
struct Obj {
    char pad0[0x118];
    signed char f118;
    char pad1[0x12C - 0x119];
    f32 f12C;
    char pad2[0x144 - 0x130];
    f32 f144;
};

extern "C" void func_0024A2F8(Obj *) throw();
extern "C" void mColorChipFace__virtual_69(Obj *, Arg1 *, s32);

extern "C" void mToolTipFace__virtual_69(Obj *self, Arg1 *arg1, s32 arg2) {
    s32 hit;
    mColorChipFace__virtual_69(self, arg1, 0);
    if (arg2 != 0) {
        hit = 0;
        f32 a = self->f144;
        f32 d = self->f12C - a;
        if (self->f118 >= 4 && d > -0x1.999998p-4f && d < 0x1.999998p-4f) {
            s32 flags = arg1->f6E8;
            Target *t = arg1->tgt;
            if (flags & 1) {
                VEnt *e = &t->vt->e;
                if (e->fn((char *)t + e->adj, 0) & 0x400) hit = 1;
            }
            if (flags & 2) {
                VEnt *e = &t->vt->e;
                if (e->fn((char *)t + e->adj, 1) & 0x400) hit = 1;
            }
        }
        if (hit == 0) func_0024A2F8(self);
    }
}
