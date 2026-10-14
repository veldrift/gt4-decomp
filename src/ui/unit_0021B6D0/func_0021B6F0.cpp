/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
static inline char *grab(Rep *r) {
    char *d = (char *)(r + 1);
    if (r->sel) d = func_005C2560(r);
    else r->ref = r->ref + 1;
    return d;
}
struct Str { char *p; Str():p(grab(&D_00659FA8)) {} };
struct Vec { float x, y, z; Vec() { z = y = x = 0.0f; } };
struct Obj { Str name; int flag; Vec a, b, c; Obj() __asm__("func_0021B6F0"); };
Obj::Obj():flag(1) {}
