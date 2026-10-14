/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct RefCounter;
struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
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
    s32 unk10;
};

static inline s32 vcall(Arg4 *a) {
    ObjA *obj = a->obj;
    VEntry *e = obj->vtbl + 11;
    return e->fn((char *)obj + e->delta);
}

extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1) throw();
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hInt__virtual_34(Self *arg0, s32 *arg1, s32 arg2, s32 arg3, Arg4 *arg4) {
    s32 buf[4];
    s32 v = 0;
    if (arg0->unk10 != 0 || vcall(arg4)) {
        v = 1;
    }
    func_002FE278(buf, v);
    if (arg1 != buf) {
        v = buf[0];
        if (v != 0) {
            func_003285A8((RefCounter *)v);
        }
        s32 old = *arg1;
        if (old != 0) {
            func_003285F8((RefCounter *)old);
        }
        *arg1 = v;
    }
    func_002FC870(buf, 2);
}
