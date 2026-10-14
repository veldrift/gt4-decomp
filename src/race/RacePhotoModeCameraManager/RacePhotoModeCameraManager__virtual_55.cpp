/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Cam {
    s32 pad0;
    s32 mode;
    f32 cx;
    f32 cy;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
};

struct Src {
    char pad0[0x18];
    s32 f18;
};

struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(void *);
};

struct VTab {
    char pad[0x1E8];
    VEnt e;
};

struct Obj {
    VTab *vt;
    char pad0[0xD10 - 4];
    Src *src;
    char pad1[0xF38 - 0xD14];
    Cam cam;
};

extern "C" void func_001C5D70(Cam *);
extern "C" void func_00374B58(Obj *, s32, f32 *, s32, f32, f32, f32) throw();
extern "C" s32 func_00378578(f32, f32) throw() __attribute__((const));

extern "C" Cam *RacePhotoModeCameraManager__virtual_55(Obj *self) {
    Cam *cam = &self->cam;
    Src *src = self->src;
    f32 v[4];
    func_001C5D70(cam);
    if (src != 0) {
        s32 s0 = src->f18;
        VEnt *e = &self->vt->e;
        s32 a1 = e->fn((char *)self + e->adj);
        s32 bad;
        f32 x0, y0, x1, y1;
        func_00374B58(self, a1, v, s0, 0x1.333332p-3f, 0x1.999998p+0f, 0x1.666666p+0f);
        x0 = v[0];
        y0 = v[1];
        x1 = v[2];
        y1 = v[3];
        bad = 0;
        if (func_00378578(x0, y0) == 0) bad = 1;
        if (func_00378578(x1, y1) == 0) bad = 1;
        if (!bad) {
            if (x0 <= -1.0f) x0 = -1.0f;
            if (x0 >= 1.0f) x0 = 1.0f;
            if (y0 <= -1.0f) y0 = -1.0f;
            if (y0 >= 1.0f) y0 = 1.0f;
            if (x1 <= -1.0f) x1 = -1.0f;
            if (x1 >= 1.0f) x1 = 1.0f;
            if (y1 <= -1.0f) y1 = -1.0f;
            if (y1 >= 1.0f) y1 = 1.0f;
            cam->mode = 3;
            cam->x0 = x0;
            cam->x1 = x1;
            cam->y0 = y0;
            cam->y1 = y1;
            cam->cx = (x0 + y0) * 0.5f;
            cam->cy = (x1 + y1) * 0.5f;
        }
    }
    return cam;
}
