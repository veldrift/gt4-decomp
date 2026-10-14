typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Vec { float x, y, z, w; };

extern "C" void func_00105280(void *, int);
extern "C" s32 func_001052E0(void *, s32, s32, s32);
extern "C" void func_001079C8(int, int);
extern "C" void func_0033E828(void *, void *);
extern "C" void func_0033E8E0(void *);
extern "C" void func_0033E960(void *, void *, int, void *, int, float);
extern "C" void func_0033EAB8(void *, s32 *, s32, void *, s32, float);
extern "C" void func_0033F1C8(void *, s32 *, s32 *, s32, float);
extern "C" void func_0033F2E8(void *, s32 *, s32, void *, float);

typedef char *(*GetFn)(char *, s32);
typedef char *(*Get2Fn)(char *);
typedef Vec (*VecFn)(char *, float);

extern "C" void func_0033E368(char *arg0, s32 *arg1, s32 arg2, s32 arg3, float fparg0) {
    char sp[0x40];
    func_0033E8E0(arg0);
    s32 s2 = *(s32 *)(arg0 + 0xE330);
    func_001052E0(sp, 2, s2, s2);
    if (*(s32 *)(arg0 + 0xE34C) != 0)
        func_001079C8(0, 0);
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *o1 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    VEntry *e2 = (VEntry *)(*(char **)o1 + 0x160);
    char *o2 = ((Get2Fn)e2->fn)(o1 + e2->delta);
    char **p = *(char ***)(o2 + 0x2880);
    if (p != 0) {
        char *o3 = *p;
        VEntry *e3 = (VEntry *)(*(char **)o3 + 0x28);
        Vec v = ((VecFn)e3->fn)(o3 + e3->delta, fparg0);
        VEntry *e4 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
        char *o4 = ((GetFn)e4->fn)(arg0 + e4->delta, 0);
        s32 t = -1;
        if (s2 >= 0x101)
            t = *arg1;
        func_0033E960(arg0, sp, (s32)o4, &v, t, fparg0);
    }
    func_0033EAB8(arg0, arg1, arg2, sp, arg3, fparg0);
    func_0033E828(arg0, arg1);
    func_0033F1C8(arg0, arg1, arg1, arg2, fparg0);
    func_0033F2E8(arg0, arg1, arg2, sp, fparg0);
    func_00105280(sp, 2);
}
