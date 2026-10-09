extern "C" {
    extern char D_0067D7C0[];
    extern char D_0067DC70[];
    extern char D_0067DAE0[];
    extern char D_0067D950[];
}

struct SpecialGeometry {
    void *vtbl;
    void *state;
};
struct NormalGeometry {
    void *vtbl;
    void *context;
    void *geometry;
};
struct CarGeometry {
    void *vtbl;
    SpecialGeometry special;
    void *baseVtbl;
    NormalGeometry normal;
    void *implementation;
};

extern "C" int func_0038DC30(CarGeometry *, void *, void *, void *);

extern "C" int CarGeometry__structor_1(CarGeometry *arg0, void *arg1, void *arg2) {
    arg0->vtbl = D_0067D7C0;
    SpecialGeometry *special = &arg0->special;
    special->vtbl = D_0067DC70;
    special->state = 0;
    arg0->baseVtbl = D_0067DAE0;
    NormalGeometry *normal = &arg0->normal;
    normal->vtbl = D_0067D950;
    normal->geometry = 0;
    arg0->implementation = 0;
    return func_0038DC30(arg0, 0, arg1, arg2);
}
