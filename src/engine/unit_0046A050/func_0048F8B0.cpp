extern char PDISTD__global_font_manager[];
extern char D_00624984[];

extern "C" void *exception__structor_0(int size);
extern "C" void func_0048FAA8(void *self);

extern "C" void func_0048F8B0(void) {
    void **slot;
    void *obj;
    slot = (void **)PDISTD__global_font_manager;
    if (*slot == 0) {
        obj = exception__structor_0(0xA4);
        func_0048FAA8(obj);
        *slot = obj;
    }
    slot = (void **)D_00624984;
    if (*slot == 0) {
        obj = exception__structor_0(0xA4);
        func_0048FAA8(obj);
        *slot = obj;
    }
}
