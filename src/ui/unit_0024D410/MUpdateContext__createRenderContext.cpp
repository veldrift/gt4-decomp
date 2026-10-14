typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_0024E3D0(void *buf, s32 arg);
extern "C" void func_0024E378(void *buf, s32 arg);
extern "C" void func_00251998(s32 a, s32 b);

extern "C" void MUpdateContext__createRenderContext(s32 unused, s32 arg1, s32 arg2, Arg3 *arg3) {
    if (arg2 == 1) {
        ObjA *obj = arg3->obj;
        VEntry *entry = obj->vtbl + 11;
        s32 result = entry->fn((char *)obj + entry->delta);
        s32 buf[4];

        func_0024E3D0(buf, arg1);
        func_00251998(buf[0], result);
        func_0024E378(buf, 2);
    }
}
