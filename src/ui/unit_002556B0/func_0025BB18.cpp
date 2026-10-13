typedef int s32;
typedef float f32;

struct Rect {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
};

struct Obj {
    char pad[0x54];
    void *parent;
};

extern "C" void func_0025BA38(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025BAA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern "C" s32 func_00267698(struct Obj *arg0);

extern "C" void func_0025BB18(struct Obj *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph) {
    f32 sA;
    f32 sB;
    f32 sC;
    f32 sD;

    switch (func_00267698(self)) {
    case 1:
        func_0025BAA0(self->parent, &sA, &sB, &sC, &sD);
        if (px != 0) *px = r->x * sC + sA;
        if (py != 0) *py = r->y * sD + sB;
        if (pw != 0) *pw = r->w * sC;
        if (ph != 0) *ph = r->h * sD;
        break;
    case 2:
        sD = 0.0f;
        sC = 0.0f;
        if (self->parent != 0) func_0025BA38(self->parent, &sD, &sC);
        if (px != 0) *px = r->x + sD;
        if (py != 0) *py = r->y + sC;
        if (pw != 0) *pw = r->w;
        if (ph != 0) *ph = r->h;
        break;
    case 3:
        if (px != 0) *px = r->x;
        if (py != 0) *py = r->y;
        if (pw != 0) *pw = r->w;
        if (ph != 0) *ph = r->h;
        break;
    }

    if (pw != 0 && *pw < 0.0f) *pw = 0.0f;
    if (ph != 0 && *ph < 0.0f) *ph = 0.0f;
}
