/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline f32 absf(f32 a) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }

extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
extern "C" f32 func_0044FA70(void *);
extern "C" f32 func_0044FA80(void *);
extern "C" f32 func_0044FA90(void *);

extern "C" f32 func_0040F670(f32 x) {
    f32 lim[2];
    lim[0] = 0x1.5fdbbcp+3f;
    lim[1] = 0x1.2d97c6p+5f;
    f32 s = 1.5f;
    if (DRIVERSUPPORT_NAME__GetMotoristDynamicParameter() != 0) {
        s = func_0044FA70(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        lim[0] = func_0044FA80(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        lim[1] = func_0044FA90(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
    }
    return minf(maxf(absf(x) * s, lim[0]), lim[1]);
}
