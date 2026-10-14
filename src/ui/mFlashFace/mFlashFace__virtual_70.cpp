/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta, index; void (*fn)(void *, void *, float, float, float); };
struct Actor { int count; char *vt; int active; };
struct Obj { char pad[0xA4]; Actor *actor; char pad2[8]; float time; };
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" float mWidget__getWindowW(void *);
extern "C" float mWidget__getWindowH(void *);
static inline void render(Actor *o, void *ctx, float w, float h, float time) {
    VE *e = (VE *)(o->vt + 0x70);
    e->fn((char *)o + e->delta, ctx, w, h, time);
}
extern "C" void mFlashFace__virtual_70(Obj *self, void *arg1, int arg2) {
    mWidget__virtual_70(self, arg1, 0);
    if (arg2 && self->actor && self->actor->active) {
        float w = mWidget__getWindowW(self);
        float h = mWidget__getWindowH(self);
        render(self->actor, arg1, w, h, self->time);
    }
}
