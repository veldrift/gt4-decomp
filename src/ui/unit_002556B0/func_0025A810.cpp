typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_0025A810(char *arg0, s32 *arg1);
extern "C" s32 func_00206868(char *arg0);
extern "C" s32 func_0025C300(char *arg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0025A810(char *arg0, s32 *arg1) {
    s32 *dst = (s32 *)(arg0 + 0x30);
    s32 newVal;
    s32 oldVal;
    VEntry *e;
    s32 r;

    if (dst != arg1) {
        newVal = *arg1;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }

    e = (VEntry *)(((Obj *)arg0)->vtbl + 0x1B0);
    if (e->fn(arg0 + e->delta) != 0) {
        r = func_00206868(arg0);
        if (r != 0) {
            do {
                func_0025A810((char *)r, dst);
                r = func_0025C300((char *)r);
            } while (r != 0);
        }
    }
}
