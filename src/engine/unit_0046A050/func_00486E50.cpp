struct V4 { float x, y, z, w; };
extern V4 D_006248E0;
extern char D_006248F0[];
extern char D_00624920[];
extern "C" void func_0048D7F8(void *, float, float, float, float, float, float, float, float, float);
extern "C" void func_0048E110(void *, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);

static inline void i1(int ini) {
    if (ini == 1) {
        D_006248E0.x = 1.0f;
        D_006248E0.y = 0.0f;
        D_006248E0.w = 1.0f;
        D_006248E0.z = 0.0f;
    }
}
static inline void i2(int ini) {
    if (ini == 1) {
        float o = 1.0f, z = 0.0f;
        func_0048D7F8(D_006248F0, o, z, z, z, o, z, z, z, o);
    }
}
static inline void i3(int ini) {
    if (ini == 1) {
        float o = 1.0f, z = 0.0f;
        func_0048E110(D_00624920, o, z, z, z, z, o, z, z, z, z, o, z, z, z, z, o);
    }
}
extern "C" void func_00486E50(int ini, int pri) {
    if (pri == 0xFFFF) {
        i1(ini);
        i2(ini);
        i3(ini);
    }
}
