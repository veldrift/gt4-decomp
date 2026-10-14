/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
extern "C" float func_0044F850(Obj *o) throw();
extern "C" float func_0044F870(Obj *o) throw();
static inline float fabs_s(float x) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" float func_0044FCA0(Obj *o, float x) {
    float a = fabs_s(x);
    if (a <= func_0044F850(o)) return 0.0f;
    if (func_0044F870(o) <= a) return 1.0f;
    float lo = func_0044F850(o);
    float hi = func_0044F870(o);
    return (a - lo) / (hi - func_0044F850(o));
}
