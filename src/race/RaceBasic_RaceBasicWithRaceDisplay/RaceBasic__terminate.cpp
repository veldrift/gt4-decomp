typedef int s32;
typedef short s16;
typedef float f32;

struct Obj_0038AAB0 {
    char pad0[0x64];
    char *inner;
    char pad1[0xE424 - 0x68];
    void *lock;
};

struct VEntry_0038AAB0 {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a);
};

extern "C" void func_003D8A60(void *p);
extern "C" void func_00389ED8(Obj_0038AAB0 *self, s32 arg1, f32 fparg0, f32 fparg1);

extern "C" void func_0038AAB0(Obj_0038AAB0 *o, s32 arg1, f32 fparg0, f32 fparg1) {
    void *p = o->lock;
    if (p != 0) {
        func_003D8A60(p);
    }
    VEntry_0038AAB0 *e = (VEntry_0038AAB0 *)(o->inner + 0x470);
    e->fn((char *)o + e->delta, 1);
    func_00389ED8(o, arg1, fparg0, fparg1);
}
