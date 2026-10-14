#include "spr.h"
struct Rect { int w, h, sx, sy; };
struct View { char pad[0x288]; Rect r; };
extern "C" void func_004A2D60(View *);
extern "C" long func_004A2E98(View *);
static inline void set(View *v, int a, int b, int c, int d) { v->r.w = a; v->r.h = b; v->r.sx = c; v->r.sy = d; }
extern "C" long func_004A2D20(int a, int b, int c, int d) {
    View *v = (View *)spr_base();
    set(v, a, b, c, d);
    func_004A2D60(v);
    return func_004A2E98(v);
}
