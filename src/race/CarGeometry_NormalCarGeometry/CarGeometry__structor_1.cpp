extern "C" {
    extern char CarGeometry__vtable[];
    extern char MTRGeometry__vtable[];
    extern char SpecialCarGeometry__vtable[];
    extern char NormalCarGeometry__vtable[];
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
    arg0->vtbl = CarGeometry__vtable;
    SpecialGeometry *special = &arg0->special;
    special->vtbl = MTRGeometry__vtable;
    special->state = 0;
    arg0->baseVtbl = SpecialCarGeometry__vtable;
    NormalGeometry *normal = &arg0->normal;
    normal->vtbl = NormalCarGeometry__vtable;
    normal->geometry = 0;
    arg0->implementation = 0;
    return func_0038DC30(arg0, 0, arg1, arg2);
}
