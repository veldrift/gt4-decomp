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

extern "C" s32 func_00265D98(Obj *arg0);
extern "C" s32 func_00265E70(Obj *arg0);
extern "C" void func_00266690(void *arg0, s32 arg1);
extern "C" void func_00266760(Obj *arg0, s32 arg1);
extern "C" void func_00266830(Obj *arg0, s32 arg1);
extern "C" s32 func_00267698(Obj *arg0);
extern "C" s32 func_00206868(Obj *arg0);
extern "C" s32 func_0025C300(Obj *arg0);
extern "C" void func_00266900(Obj *arg0, s32 arg1);

extern "C" void func_00266900(Obj *arg0, s32 arg1) {
    Obj *p;

    if (func_00265D98(arg0) != 0) {
        if ((func_00267698(arg0) ^ 1) != 0) {
            if (func_00265E70(arg0) != 0) {
                func_00266760(arg0, 0);
            } else {
                func_00266690(arg0, 0);
            }
        }
    } else {
        if ((func_00267698(arg0) ^ 2) != 0) {
            if (func_00265E70(arg0) != 0) {
                func_00266830(arg0, 0);
            } else {
                func_00266760(arg0, 0);
            }
        }
    }
    if (arg1 != 0) {
        Obj *self = (Obj *)arg0;
        VEntry *e = (VEntry *)(self->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            p = (Obj *)func_00206868(arg0);
            if (p != 0) {
                do {
                    func_00266900(p, arg1);
                    p = (Obj *)func_0025C300(p);
                } while (p != 0);
            }
        }
    }
}
