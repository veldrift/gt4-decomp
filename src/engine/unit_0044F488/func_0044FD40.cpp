/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
extern "C" float func_0044F860(Obj *o) throw();
extern "C" float func_0044F880(Obj *o) throw();
static inline float fabs_s(float x) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" float func_0044FD40(Obj *o, float x) {
    float a = fabs_s(x);
    if (a <= func_0044F860(o)) return 0.0f;
    if (func_0044F880(o) <= a) return 1.0f;
    float lo = func_0044F860(o);
    float hi = func_0044F880(o);
    return (a - lo) / (hi - func_0044F860(o));
}
