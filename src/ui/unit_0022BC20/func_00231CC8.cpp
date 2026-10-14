struct Rect {
    float x, y, w, h;
    Rect() {}
    Rect(float a, float b, float c, float d) : x(a), y(b), w(c), h(d) {}
    Rect(const Rect &r) : x(r.x), y(r.y), w(r.w), h(r.h) {}
};
extern "C" int func_002319F0(void *) throw();
extern "C" const Rect *func_00231A38(void *) throw();
extern "C" Rect func_00231460(void *);

static inline Rect intersect(const Rect &a, const Rect &b) {
    float ax = a.x, bx = b.x; float x = bx < ax ? ax : bx;
    float ay = a.y, by = b.y; float y = by < ay ? ay : by;
    float ar = ax + a.w, br = b.x + b.w; float w = (br < ar ? br : ar) - x;
    float ab = ay + a.h, bb = by + b.h; float h = (bb < ab ? bb : ab) - y;
    if (w <= 0 || h <= 0) w = h = 0;
    return Rect(x, y, w, h);
}
static inline bool nonempty(const Rect &r) { return 0 < r.w && 0 < r.h; }

extern "C" int func_00231CC8(void *self) {
    if (func_002319F0(self)) {
        const Rect *clip = func_00231A38(self);
        Rect overlap = intersect(*clip, func_00231460(self));
        return nonempty(overlap);
    }
    return 1;
}
