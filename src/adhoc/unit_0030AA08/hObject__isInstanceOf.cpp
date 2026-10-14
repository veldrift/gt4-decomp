/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};
struct Self {
    char pad0[4];
    char *vtbl;
};
extern "C" s32 func_002F3A28(s32);

extern "C" s32 hObject__isInstanceOf(Self *arg0, s32 arg1) {
    VEntry *e = (VEntry *)(arg0->vtbl + 0x50);
    s32 a = e->fn((char *)arg0 + e->delta);
    while (a != 0) {
        if (arg1 == a) {
            return 1;
        }
        a = func_002F3A28(a);
    }
    return 0;
}
