typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct S {
    char pad0[4];
    char *vtbl;
};

struct VE {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" int func_00206868(S *arg0);
extern "C" u32 func_00206880(S *arg0);
extern "C" s32 func_0025C300(S *arg0);
extern "C" void func_00265D10(S *arg0, s32 arg1);
extern "C" s32 func_003065A8(S *arg0);

extern "C" void func_00218910(S *arg0) {
    S *p;
    u32 t;
    VE *e = (VE *)(arg0->vtbl + 0x1B0);

    if (e->fn((void *)((char *)arg0 + e->delta)) != 0) {
        t = (u32)func_003065A8(arg0);
        func_00265D10(arg0, func_00206880(arg0) < t);
        p = (S *)func_00206868(arg0);
        if (p != 0) {
            do {
                func_00218910(p);
                p = (S *)func_0025C300(p);
            } while (p != 0);
        }
    } else {
        func_00265D10(arg0, func_003065A8(arg0) != 0);
    }
}
