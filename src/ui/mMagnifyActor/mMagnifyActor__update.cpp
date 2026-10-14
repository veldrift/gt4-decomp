/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x14]; void *target; float phase, x, y, width, height; int repeat, reverse; float step; };
extern "C" void func_0025B538(void *, float, float, float, float);
extern "C" void mMagnifyActor__update(Obj *self) {
    if (self->reverse == 0) self->phase = self->phase + self->step; else self->phase = self->phase - self->step;
    if (self->repeat != 0 && (self->phase <= 0.5f || self->phase >= 2.0f)) self->phase = 1.0f;
    float phase = self->phase;
    float x = self->x; float y = self->y; float width = self->width; float height = self->height;
    float w = width * phase; float h = height * phase;
    func_0025B538(self->target, x + (width - w) * 0.5f, y + (height - h) * 0.5f, w, h);
}
