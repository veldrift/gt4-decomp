/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Rect { f32 x, y, w, h; Rect() {} Rect(const Rect &r) { x=r.x; y=r.y; w=r.w; h=r.h; } };

extern "C" void *func_00206868(void *) throw();
extern "C" void func_0025B500(void *, f32 *, f32 *, f32 *, f32 *);
extern "C" void *func_0025C300(void *);

static inline void init(Rect *r, f32 a, f32 b, f32 c, f32 d) {
    r->x = a;
    r->y = b;
    r->w = c;
    r->h = d;
}

static inline float minval(float a,float b) { return a < b ? a : b; }
static inline float maxval(float a,float b) { return a < b ? b : a; }
static inline void unite(Rect *a, Rect *t) {
 float x = minval(t->x,a->x);
 float y = minval(t->y,a->y);
 float r = maxval(t->x+t->w,a->x+a->w);
 float b = maxval(t->y+t->h,a->y+a->h);
 a->x=x; a->y=y; a->w=r-x; a->h=b-y;
}

extern "C" Rect func_00208568(void *obj) {
    Rect acc;
    init(&acc, 0.0f, 0.0f, 0.0f, 0.0f);
    void *n = func_00206868(obj);
    if (n != 0) {
        do {
            Rect t;
            Rect *pt = &t;
            init(&t, 0.0f, 0.0f, 0.0f, 0.0f);
            func_0025B500(n, &t.x, &t.y, &t.w, &t.h);
            unite(&acc, pt);
            n = func_0025C300(n);
        } while (n != 0);
    }
    return acc;
}
