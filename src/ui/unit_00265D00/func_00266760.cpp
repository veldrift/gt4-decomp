typedef int s32;
typedef short s16;
typedef float f32;

struct VE {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" s32 func_00267698(Obj *arg0);
extern "C" void func_0025BAA0(Obj *arg0, void *a1, void *a2, void *a3, void *a4);
extern "C" void func_002676A8(Obj *arg0, s32 arg1);
extern "C" void func_0025BAD8(Obj *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" Obj *func_00206868(Obj *arg0);
extern "C" Obj *func_0025C300(Obj *arg0);
extern "C" void func_00266760(Obj *arg0, s32 arg1);

extern "C" void func_00266760(Obj *arg0, s32 arg1) {
    f32 buf[4];
    Obj *p;

    if ((func_00267698(arg0) ^ 2) != 0) {
        func_0025BAA0(arg0, buf, buf + 1, buf + 2, buf + 3);
        func_002676A8(arg0, 2);
        func_0025BAD8(arg0, buf[0], buf[1], buf[2], buf[3]);
    }
    if (arg1 != 0) {
        VE *e = (VE *)(arg0->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            p = func_00206868(arg0);
            if (p != 0) {
                do {
                    func_00266760(p, arg1);
                    p = func_0025C300(p);
                } while (p != 0);
            }
        }
    }
}
