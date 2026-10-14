/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

extern char RebuildPropagate__vtable[];

struct VE2355E0 { s16 delta; s16 index; void *fn; };

extern "C" void func_00234810(void *, s32, float, float);
extern "C" void *func_00235C00(void *);
extern "C" void func_005DB760(void *);

extern "C" void RebuildPropagate__structor_0(void *arg0) {
    s32 sp[4];
    char *vt;
    struct VE2355E0 *e;
    void *fn;
    func_005DB760((char *)arg0 + 0xC0);
    sp[0] = (s32)RebuildPropagate__vtable;
    vt = *(char **)((char *)arg0 + 4);
    sp[1] = (s32)arg0;
    e = (struct VE2355E0 *)(vt + 0x1F8);
    fn = e->fn;
    ((void (*)(void *, void *))fn)((char *)arg0 + e->delta, sp);
    if (func_00235C00(arg0) == 0) {
        func_00234810(arg0, 1, 0.0f, 0.0f);
    }
}
