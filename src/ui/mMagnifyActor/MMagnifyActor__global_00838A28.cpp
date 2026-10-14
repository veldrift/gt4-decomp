/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { s32 unk0; char *vtbl; };
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_002B97D8(void *, int) throw();
extern "C" void func_002B9830(void *, void *) throw();
extern "C" s32 func_002BA1E0(void *, s32);
extern "C" void func_002BA248(void *, float);
extern "C" void func_002F7B68(void *, int);
extern "C" void func_002F7BC0(void *, void *);
extern "C" float func_002F9158(void *);
struct H0 {
    Obj *p; char pad[12];
    H0(void *) throw() __asm__("func_002B9830");
    ~H0() throw() __asm__("func_002B97D8");
};
struct H1 {
    s32 p; char pad[12];
    s32 get() const { return p; }
    H1(void *) __asm__("func_00255110");
    ~H1() __asm__("func_002550B8");
};
struct H2 {
    void *p; char pad[12];
    void *get() const { return p; }
    H2(void *) __asm__("func_002F7BC0");
    ~H2() __asm__("func_002F7B68");
};
extern "C" void MMagnifyActor__global_00838A28(void *arg0, void *arg1, s32 n, char *args) {
    if (n > 0) {
        H0 h0(arg1);
        H1 h1(args);
        Obj *o = h0.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x190);
        e->fn((char *)o + e->delta);
        func_002BA1E0(h0.p, h1.get());
        if (n >= 2) {
            H2 h2(args + 4);
            Obj *target = h0.p;
            float f = func_002F9158(h2.get());
            func_002BA248(target, f);
        }
    }
}
