typedef int s32;
struct Rect {
    float x, y, w, h;
    Rect() {}
    Rect(float a, float b, float c, float d) : x(a), y(b), w(c), h(d) {}
    Rect(const Rect &r) : x(r.x), y(r.y), w(r.w), h(r.h) {}
    Rect &operator=(const Rect &o) {
        if (this != &o) { x = o.x; y = o.y; w = o.w; h = o.h; }
        return *this;
    }
};
extern char D_0082E550[];
extern "C" s32 func_00230AE0(Rect *, Rect *) throw();
extern "C" void func_0025BAA0(void *, float *, float *, float *, float *);
extern "C" s32 func_00268408(void *);
extern "C" s32 func_00268440(void *);
extern "C" void func_005769F0(char *);
extern "C" void func_00576A28(char *);

extern "C" void func_00230B68(char *self, void *obj) {
    if (obj != 0 && func_00268408(obj) != 0) {
        Rect r(0.0f, 0.0f, 0.0f, 0.0f);
        float *px = &r.x;
        func_0025BAA0(obj, px, &r.y, &r.w, &r.h);
        r.w += r.x;
        r.h += r.y;
        func_005769F0(D_0082E550);
        if (func_00230AE0(((Rect *)(self + 0x1D14)), &r) == 0) {
            *((Rect *)(self + 0x1D14)) = r;
            *(s32 *)(self + 0x1D28) = 1;
        }
        if (*(s32 *)(self + 0x1D24) != func_00268440(obj)) {
            s32 v = func_00268440(obj);
            *(s32 *)(self + 0x1D24) = v;
            *(s32 *)(self + 0x1D28) = 1;
        }
        func_00576A28(D_0082E550);
    }
}
