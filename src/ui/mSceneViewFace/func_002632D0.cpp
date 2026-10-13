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

extern "C" void func_0025A788(Obj *arg0, Obj *arg1);
extern "C" s32 func_00206868(Obj *arg0);
extern "C" s32 func_0025C2F8(Obj *arg0);
extern "C" s32 func_0025C300(Obj *arg0);
extern "C" void func_002632D0(Obj *arg0, Obj *arg1);

extern "C" void func_002632D0(Obj *arg0, Obj *arg1) {
    Obj *p;
    Obj *q;

    func_0025A788(arg0, arg1);
    {
        VEntry *e = (VEntry *)(arg0->vtbl + 0x1B0);
        if (e->fn((char *)arg0 + e->delta) != 0) {
            p = (Obj *)func_00206868(arg0);
            q = (Obj *)func_00206868(arg1);
            if (p != 0) {
                do {
                    func_002632D0(p, q);
                    p = (Obj *)func_0025C300(p);
                    q = (Obj *)func_0025C2F8(q);
                } while (p != 0);
            }
        }
    }
}
