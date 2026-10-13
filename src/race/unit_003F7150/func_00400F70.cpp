typedef float f32;

extern "C" f32 func_00421BF8(void);

static inline f32 max_s(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" f32 func_00400F70(void) {
    f32 v = func_00421BF8();
    return min_s(max_s(v, 0.0f), 1.0f);
}
