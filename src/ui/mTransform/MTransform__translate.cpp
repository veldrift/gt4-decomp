typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_0024B248(void *arg0, int arg1);
extern "C" void func_0024B2A0(void *arg0, void *arg1);
extern "C" void func_0024BEB0(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_0024B538(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    char *h[4];
    if (arg2 == 2) {
        func_0024B2A0(h, arg1);
        {
            char *hv = h[0];
            VObj *o = arg3[0];
            VEntryF *e = (VEntryF *)(o->vtbl + 0x60);
            f32 f = e->fn((char *)o + e->delta);
            VObj *o2 = arg3[1];
            VEntryF *e2 = (VEntryF *)(o2->vtbl + 0x60);
            func_0024BEB0(hv, f, e2->fn((char *)o2 + e2->delta));
        }
        func_0024B248(h, 2);
    }
}
