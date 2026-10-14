/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef float f32;

struct RefCounter;
struct VEntry {
    s16 delta;
    s16 pad;
    f32 (*fn)(void *);
};
struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};
struct Arg4 {
    ObjA *obj;
};
struct Self {
    char pad0[0x10];
    f32 unk10;
};

extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

static inline f32 vcall(ObjA *obj) {
    VEntry *e = obj->vtbl + 12;
    return e->fn((char *)obj + e->delta);
}
extern "C" void hFloat__virtual_34(Self *arg0, RefCounter **arg1, s32 arg2, s32 arg3, Arg4 *arg4) {
    RefCounter *buf[4];
    s32 v = 0;
    if (arg0->unk10 != 0.0f || vcall(arg4->obj) != 0.0f) v = 1;
    func_002FE278(buf, v);
    if (arg1 != buf) {
        RefCounter *newVal = buf[0];
        if (newVal != 0) func_003285A8(newVal);
        RefCounter *oldVal = *arg1;
        if (oldVal != 0) func_003285F8(oldVal);
        *arg1 = newVal;
    }
    func_002FC870(buf, 2);
}
