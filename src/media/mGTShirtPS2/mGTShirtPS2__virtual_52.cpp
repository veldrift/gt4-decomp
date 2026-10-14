/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct R { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; char pad[8]; };
struct C { char b[0x10]; };
struct Obj {
    char pad0[0x270]; s32 f270; s32 f274; char pad278[8]; s32 f280;
};
struct Tgt { s32 pad0; char *vt; };
extern "C" void func_001C2E90(R *, Obj *) throw();
extern "C" C *func_00203148(C *, float, float, float, float);
extern "C" void func_00203118(C *, s32);
extern "C" void mGTShirtPS2__virtual_52(Obj *self, Tgt *tgt, s32 flip, float sx, float sy) {
    R r;
    C c;
    if (self->f280 != 0) {
        func_001C2E90(&r, self);
        if (r.f0 != 0) {
            float t270 = (float)self->f270;
            float t274 = (float)self->f274;
            float a = (float)r.f8;
            float b = (float)r.f10;
            float fx = sx / t270;
            float c0 = (float)r.f14;
            float d0 = (float)r.fC;
            float fy = sy / t274;
            if (flip != 0) a = (320.0f - a) - b;
            a *= fx;
            d0 *= fy;
            b *= fx;
            c0 *= fy;
            func_00203148(&c, 0.7f, 0.7f, 0.0f, 1.0f);
            VE *e = (VE *)(tgt->vt + 0x198);
            ((void (*)(void *, C *))e->fn)((char *)tgt + e->delta, &c);
            func_00203118(&c, 2);
            VE *e2 = (VE *)(tgt->vt + 0x1A8);
            ((void (*)(void *, float, float, float, float))e2->fn)((char *)tgt + e2->delta, a, d0, b, c0);
        }
    }
}
