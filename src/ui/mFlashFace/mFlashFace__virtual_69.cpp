/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
struct VE { s16 delta, index; void (*fn)(void *, int); };
struct VF { s16 delta, index; float (*fn)(void *); };
struct Actor { int count; char *vt; int active; };
struct Obj { char pad[0xA4]; Actor *actor; char pad2[8]; float time; int flags; };
extern "C" void mColorChipFace__virtual_69(void *, int, int);
static inline void update(Actor *o, int b) {
    VE *e = (VE *)(o->vt + 0x68);
    e->fn((char *)o + e->delta, b);
}
static inline float duration(Actor *o) {
    VF *e = (VF *)(o->vt + 0x78);
    return e->fn((char *)o + e->delta);
}
extern "C" void mFlashFace__virtual_69(Obj *self, int arg1, int arg2) {
    mColorChipFace__virtual_69(self, arg1, 0);
    if (arg2 && self->actor && self->actor->active) {
        int flags = self->flags;
        int loop = flags >> 6;
        loop &= 1;
        flags &= 0x80;
        if (!flags) {
            update(self->actor, loop);
            self->time += 1.0f / 60.0f;
            if (duration(self->actor) <= self->time) {
                if ((self->flags >> 6) & 1) self->time = 0.0f;
                else self->time = duration(self->actor);
            }
        }
    }
}
