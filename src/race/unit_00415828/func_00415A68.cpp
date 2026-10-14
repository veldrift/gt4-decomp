typedef float f32;

extern "C" f32 func_0057D2B8(f32 x) throw();

extern "C" f32 func_00415A68(f32 a, f32 b, f32 c) {
    f32 r = 0.0f;
    if (a <= 0.0f) {
        return r;
    }
    if (a >= 1.0f) {
        return r;
    }
    f32 t;
    if (a < b) {
        t = a / b;
    } else {
        t = (1.0f - a) / (1.0f - b);
    }
    r = c * func_0057D2B8(t * 1.5707963f);
    return r;
}
