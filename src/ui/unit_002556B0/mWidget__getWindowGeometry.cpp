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

extern "C" void mWidget__getWindowSize(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025BA38(void *arg0, f32 *arg1, f32 *arg2);
extern "C" s32 func_00267698(struct Obj *arg0);

extern "C" void mWidget__getWindowGeometry(struct Obj *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph) {
    f32 sx;
    f32 sy;

    switch (func_00267698(self)) {
    case 1:
        mWidget__getWindowSize(self->parent, &sx, &sy);
        if (px != 0) *px = r->x * sx;
        if (py != 0) *py = r->y * sy;
        if (pw != 0) *pw = r->w * sx;
        if (ph != 0) *ph = r->h * sy;
        break;
    case 2:
        if (px != 0) *px = r->x;
        if (py != 0) *py = r->y;
        if (pw != 0) *pw = r->w;
        if (ph != 0) *ph = r->h;
        break;
    case 3:
        sy = 0.0f;
        sx = 0.0f;
        if (self->parent != 0) func_0025BA38(self->parent, &sy, &sx);
        if (px != 0) *px = r->x - sy;
        if (py != 0) *py = r->y - sx;
        if (pw != 0) *pw = r->w;
        if (ph != 0) *ph = r->h;
        break;
    }

    if (pw != 0 && *pw < 0.0f) *pw = 0.0f;
    if (ph != 0 && *ph < 0.0f) *ph = 0.0f;
}
