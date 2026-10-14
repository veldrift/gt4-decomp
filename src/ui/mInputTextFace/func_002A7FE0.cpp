/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Scroll { float x; float y; float z; };
struct Self {
    char pad0[0x578];
    char sub[0x864];
    Scroll sc;
    s32 started;
};

extern void *PDISTD__global_font_manager;

extern "C" s32 func_002A6570(void *) throw();
extern "C" void func_004B87F0(void *, void *, s32, s32);
extern "C" float func_00490B38(void *, s32);
extern "C" float mWidget__getWindowW(void *);
extern "C" void *func_0057B0F8(void *, float, float);
extern "C" void func_004908C0(void *, float, float);
extern "C" void func_00490A08(void *, s32, char *);
extern "C" char *func_002314E8(void *);
extern "C" s32 func_00490660(void *, float);

extern "C" void func_002A7FE0(Self *self, void *arg1) {
    s32 sp0;
    void *p = self->sub;
    Scroll *sc = &self->sc;
    s32 mode = func_002A6570(self) ? 0x2A : 0;
    func_004B87F0(p, &sp0, 1, mode);
    float bottom = func_00490B38(PDISTD__global_font_manager, sp0);
    float z0 = sc->z;
    float lo;
    float zero = 0.0f;
    float w = mWidget__getWindowW(self);
    float cur = z0;
    float hi = bottom - 16.0f;
    if (hi < cur) {
        lo = zero;
        cur = hi;
    } else {
        lo = (bottom - w) + 16.0f;
    }
    if (cur < lo) cur = lo;
    if (self->started != 0) {
        func_0057B0F8(sc, cur, 0x1.999998p-3f);
    } else {
        sc->z = cur;
        sc->y = sc->x = 0.0f;
    }
    func_004908C0(PDISTD__global_font_manager, -sc->z, 0.0f);
    func_004B87F0(p, &sp0, 2, mode);
    func_00490A08(PDISTD__global_font_manager, sp0, func_002314E8(arg1));
    func_004908C0(PDISTD__global_font_manager, -sc->z, 0.0f);
    func_00490660(PDISTD__global_font_manager, bottom);
    if (self->started == 0) self->started = 1;
}
