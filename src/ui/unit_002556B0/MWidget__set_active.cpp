typedef int s32;
typedef short s16;

struct VEntry_58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj_58 {
    s32 pad0;
    VEntry_58 *vtbl;
};

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_002550B8(void *arg0, s32 arg1);
extern "C" void mWidget__setActive(void *node, void *arg);

extern "C" void MWidget__set_active(s32 arg0, void *arg1, s32 arg2, void **arg3) {
    s32 buf[4];
    s32 s1;
    VObj_58 *obj;
    VEntry_58 *entry;
    s32 r;

    func_00255110(buf, arg1);
    obj = (VObj_58 *)*arg3;
    s1 = buf[0];
    entry = (VEntry_58 *)((char *)obj->vtbl + 0x58);
    r = entry->fn((char *)obj + entry->delta);
    mWidget__setActive((void *)s1, (void *)(s32)(r != 0));
    func_002550B8(buf, 2);
}
