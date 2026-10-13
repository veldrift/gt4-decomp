typedef float f32;

struct Cubic {
    f32 c0;
    f32 c1;
    f32 c2;
    f32 c3;
    Cubic(f32 a, f32 b, f32 c, f32 d) : c0(a), c1(b), c2(c), c3(d) {}
};

extern "C" Cubic func_00421BB8(const Cubic *p, f32 t) {
    f32 t2 = t * t;
    return Cubic(p->c0, p->c1 * t, p->c2 * t2, p->c3 * (t2 * t));
}
