typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" s32 func_00267698(void *arg0);
extern "C" void func_0025BAA0(void *arg0, void *a1, void *a2, void *a3, void *a4);
extern "C" void func_0025BAD8(void *arg0, f32 f0, f32 f1, f32 f2, f32 f3);
extern "C" void func_002676A8(void *arg0, s32 arg1);
extern "C" s32 func_00206868(void *arg0);
extern "C" s32 func_0025C300(void *arg0);
extern "C" void func_00266690(void *arg0, s32 arg1);

extern "C" void func_00266690(void *arg0, s32 arg1) {
    f32 fv[4];
    Obj *p;

    if ((func_00267698(arg0) ^ 1) != 0) {
        func_0025BAA0(arg0, fv, fv + 1, fv + 2, fv + 3);
        func_002676A8(arg0, 1);
        func_0025BAD8(arg0, fv[0], fv[1], fv[2], fv[3]);
    }
    if (arg1 != 0) {
        Obj *self = (Obj *)arg0;
        VEntry *e = (VEntry *)(self->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            p = (Obj *)func_00206868(arg0);
            if (p != 0) {
                do {
                    func_00266690(p, arg1);
                    p = (Obj *)func_0025C300(p);
                } while (p != 0);
            }
        }
    }
}
