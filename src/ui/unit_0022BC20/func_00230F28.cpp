struct Rect {
    float x, y, w, h;
    Rect(float a, float b, float c, float d) { x = a; y = b; w = c; h = d; }
    Rect &operator=(const Rect &r) {
        if (this != &r) { x = r.x; y = r.y; w = r.w; h = r.h; }
        return *this;
    }
};
struct Self {
    char pad[0x6F4]; float x; char pad1[8]; float y; char pad2[12]; Rect rect;
};
extern "C" void *func_0022F000(void *) throw();
extern "C" void func_00230A50(void *, float *, float *) throw();
extern "C" void *func_00235C00(void *);
extern "C" void func_0025BAA0(void *, float *, float *, float *, float *);
extern "C" void func_00230F28(Self *self, void *obj) {
    void *root = func_0022F000(self);
    if (obj) root = func_00235C00(obj);
    Rect r(0.0f, 0.0f, 0.0f, 0.0f);
    if (root) func_0025BAA0(root, &r.x, &r.y, &r.w, &r.h);
    else r = self->rect;
    float center[2];
    center[0] = r.x + r.w * 0.5f;
    center[1] = r.y + r.h * 0.5f;
    func_00230A50(self, &center[0], &center[1]);
    self->x = center[0];
    self->y = center[1];
}
