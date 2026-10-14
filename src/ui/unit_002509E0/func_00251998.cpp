/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x,y,z,w; };
struct VEntry { short delta, index; void *(*fn)(void *); };
struct Obj { int pad0; char *vtbl; char pad8[0xB0]; int state; void *screens[2]; };
extern "C" void func_002314B0(void *, Vec4 *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline void *create(Obj *o) {
    VEntry *v = (VEntry *)(o->vtbl + 0x1F8);
    return v->fn((char *)o + v->delta);
}
static inline void apply(Vec4 *r, void *p, float x, float y, float z, float w) {
    r->x = x; r->y = y; r->z = z; r->w = w;
    func_002314B0(p, r);
}
extern "C" void func_00251998(Obj *self, int mode) {
    Vec4 r;
    if (mode == 0) {
        self->state = 0;
        for (int i = 0; i < 2; ++i) {
            if (self->screens[i]) func_003285F8(self->screens[i]);
            self->screens[i] = 0;
        }
    } else if (mode == 1) {
        self->state = mode;
        float width = 640.0f; float height = 480.0f;
        self->screens[0] = create(self);
        func_003285A8(self->screens[0]);
        float zero = 0.0f;
        apply(&r, self->screens[0], zero, zero, width, height);
    } else if (mode == 2) {
        self->state = 2;
        float height = 240.0f; float zero = 0.0f; float width = 640.0f;
        self->screens[0] = create(self);
        func_003285A8(self->screens[0]);
        apply(&r, self->screens[0], zero, zero, width, height);
        self->screens[1] = create(self);
        func_003285A8(self->screens[1]);
        apply(&r, self->screens[1], zero, height, width, height);
    } else if (mode == 3) {
        self->state = 2;
        float width = 320.0f; float zero = 0.0f; float height = 480.0f;
        self->screens[0] = create(self);
        func_003285A8(self->screens[0]);
        apply(&r, self->screens[0], zero, zero, width, height);
        self->screens[1] = create(self);
        func_003285A8(self->screens[1]);
        apply(&r, self->screens[1], width, zero, width, height);
    }
}
