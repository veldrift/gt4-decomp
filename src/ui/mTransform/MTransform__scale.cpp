typedef int s32;
typedef short s16;
typedef float f32;

struct VEntryF_0024B498 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj_0024B498 {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_0024B248(void *arg0, int arg1);
extern "C" void func_0024B2A0(void *arg0, void *arg1);
extern "C" void func_0024BE78(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_0024B498(s32 *arg0, void *arg1, s32 arg2, VObj_0024B498 **arg3) {
    void *buf0[4];
    if (arg2 == 2) {
        func_0024B2A0(buf0, arg1);
        {
            void *hv = buf0[0];
            VObj_0024B498 *o = arg3[0];
            VEntryF_0024B498 *e = (VEntryF_0024B498 *)(o->vtbl + 0x60);
            f32 a = e->fn((char *)o + e->delta);
            VObj_0024B498 *o2 = arg3[1];
            VEntryF_0024B498 *e2 = (VEntryF_0024B498 *)(o2->vtbl + 0x60);
            func_0024BE78(hv, a, e2->fn((char *)o2 + e2->delta));
        }
        func_0024B248(buf0, 2);
    }
}
