/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Rect { f32 x, y, w, h; };
struct VE { s16 delta; s16 pad; void (*fn)(void *, f32 *, f32 *); };
struct W { char pad[4]; char *vtbl; };

extern "C" void *func_00206868(void *) throw();
extern "C" s32 func_00265D98(void *);
extern "C" void mWidget__setWindowPosition(void *, f32, f32);
extern "C" void *func_0025C300(void *);
extern "C" void func_0025B4C8(void *, f32, f32);

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

extern "C" void func_00207DB0(void *self) {
    Rect acc;
    init(&acc, 0.0f, 0.0f, 0.0f, 0.0f);
    W *n = (W *)func_00206868(self);
    if (n != 0) {
        do {
            if (func_00265D98(n) != 0) {
                Rect t;
                Rect *pt = &t;
                init(&t, 0.0f, 0.0f, 0.0f, 0.0f);
                VE *e = (VE *)(n->vtbl + 0x1B8);
                e->fn((char *)n + e->delta, &t.w, &t.h);
                mWidget__setWindowPosition(n, 0.0f, 0.0f);
                Rect *pa = &acc;
                unite(pa, pt);
            }
            n = (W *)func_0025C300(n);
        } while (n != 0);
    }
    func_0025B4C8(self, acc.w, acc.h);
}
