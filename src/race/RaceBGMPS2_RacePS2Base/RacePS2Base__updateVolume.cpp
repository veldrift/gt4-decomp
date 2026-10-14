/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct VEntry { short delta; short index; void *fn; };
struct Obj { VEntry *vt; };
struct Base { char pad0[0x64]; char *vt; char pad1[0xCF84 - 0x68]; f32 vol; };
extern f32 RaceCarSound__external_volume_;
extern "C" void RaceBGMPS2__setVolumeRate(void *, f32) throw();
static inline f32 getv(Base *self) {
    VEntry *e = (VEntry *)(self->vt + 0x478);
    return ((f32 (*)(void *))e->fn)((char *)self + e->delta);
}
static inline Obj *getobj(Base *self) {
    VEntry *e = (VEntry *)(self->vt + 0xD0);
    return ((Obj *(*)(void *, s32))e->fn)((char *)self + e->delta, 0);
}
extern "C" void RacePS2Base__updateVolume(Base *self) {
    f32 v = getv(self);
    self->vol = self->vol * 0.5f;
    Obj *o = getobj(self);
    VEntry *e2 = (VEntry *)((char *)o->vt + 0x138);
    if (((s32 (*)(void *, s32))e2->fn)((char *)o + e2->delta, 0) != 0)
        self->vol = 1.0f;
    RaceCarSound__external_volume_ = v * (1.0f - self->vol);
    RaceBGMPS2__setVolumeRate((char *)self + 0xCF88, v);
}
