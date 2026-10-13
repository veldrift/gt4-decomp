typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct C {
    char pad0[4];
};

struct S {
    char pad0[4];
};

struct Obj002676A8 {
    char pad0[4];
};

extern "C" s32 func_00206868(S *arg0);
extern "C" void func_0025BAA0(C *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" void func_0025BAD8(C *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" s32 func_0025C300(S *arg0);
extern "C" s32 func_00267698(Obj *arg0);
extern "C" void func_002676A8(Obj002676A8 *arg0, s32 arg1);
extern "C" void func_00266830(Obj *arg0, s32 arg1);

extern "C" void func_00266830(Obj *arg0, s32 arg1) {
    f32 fb[4];

    if ((func_00267698(arg0) ^ 3) != 0) {
        func_0025BAA0((C *)arg0, (s32)&fb[0], (s32)&fb[1], (s32)&fb[2], (s32)&fb[3]);
        func_002676A8((Obj002676A8 *)arg0, 3);
        func_0025BAD8((C *)arg0, fb[0], fb[1], fb[2], fb[3]);
    }
    if (arg1 != 0) {
        VEntry *e = (VEntry *)(arg0->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            Obj *p = (Obj *)func_00206868((S *)arg0);
            if (p != 0) {
                do {
                    func_00266830(p, arg1);
                    p = (Obj *)func_0025C300((S *)p);
                } while (p != 0);
            }
        }
    }
}
