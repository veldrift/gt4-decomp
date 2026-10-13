typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Rect {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
};

struct Widget {
    char pad0[0x44];
    f32 f44;
    f32 f48;
    char pad4c[0x8];
    void *parent;
    char pad58[0x40];
    u32 flags_lo : 21;
    u32 size_dirty : 1;
};

extern s32 D_00619374;

extern "C" void func_0025BA38(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025BAA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern "C" u32 func_002662A0(struct Widget *arg0);
extern "C" s32 func_00267698(struct Widget *arg0);

extern "C" void func_0025BCF0(struct Widget *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph) {
    f32 sA;
    f32 sB;
    f32 sC;
    f32 sD;
    f32 w = r->w;
    f32 h = r->h;

    switch (func_00267698(self)) {
    case 1:
        func_0025BAA0(self->parent, &sA, &sB, &sC, &sD);
        if (px != 0) r->x = (*px - sA) / sC;
        if (py != 0) r->y = (*py - sB) / sD;
        if (pw != 0) w = *pw / sC;
        if (ph != 0) h = *ph / sD;
        break;
    case 2:
        sD = 0.0f;
        sC = 0.0f;
        if (self->parent != 0) func_0025BA38(self->parent, &sD, &sC);
        if (px != 0) r->x = *px - sD;
        if (py != 0) r->y = *py - sC;
        if (pw != 0) w = *pw;
        if (ph != 0) h = *ph;
        break;
    case 3:
        if (px != 0) r->x = *px;
        if (py != 0) r->y = *py;
        if (pw != 0) w = *pw;
        if (ph != 0) h = *ph;
        break;
    }

    if (pw != 0 && w != r->w) {
        r->w = w;
        self->size_dirty = 1;
    }
    if (ph != 0 && h != r->h) {
        r->h = h;
        self->size_dirty = 1;
    }
    if (r->w < 0.0f) r->w = 0.0f;
    if (r->h < 0.0f) r->h = 0.0f;

    if (D_00619374 != 0 && func_002662A0(self) != 0) {
        self->f44 = r->w;
        self->f48 = r->h;
    }
}
