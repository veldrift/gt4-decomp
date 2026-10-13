typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" s32 func_00206868(Obj *arg0);
extern "C" s32 func_0025C300(Obj *arg0);
extern "C" void func_00266900(Obj *arg0, s32 arg1);

extern "C" void func_00267748(Obj *arg0) {
    Obj *p;

    {
        VEntry *e = (VEntry *)(arg0->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            p = (Obj *)func_00206868(arg0);
            if (p != 0) {
                do {
                    func_00266900(p, 0);
                    p = (Obj *)func_0025C300(p);
                } while (p != 0);
            }
        }
    }
}
