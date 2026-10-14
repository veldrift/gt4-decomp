/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Quadratic {
    float a,b,c;
    Quadratic(float x,float y,float z): a(x),b(y),c(z) {}
};
extern "C" Quadratic func_00421A78(const Quadratic *p, float t) {
    return Quadratic((p->a - p->b*t) + p->c*t*t, p->b - 2.0f*p->c*t, p->c);
}
