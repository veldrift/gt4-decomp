typedef float f32;
typedef short s16;

struct Widget;

struct Widget {
    char pad[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, f32 *, f32 *);
};

struct Vec2 {
    f32 x;
    f32 y;
};

extern "C" void func_0025B4C8(struct Widget *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_002A2310(struct Widget *self) {
    struct Vec2 v;
    VEntry *e = (VEntry *)(self->vtbl + 0x1B8);
    e->fn((char *)self + e->delta, &v.x, &v.y);
    func_0025B4C8(self, v.x, v.y);
}
