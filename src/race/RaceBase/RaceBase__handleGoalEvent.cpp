typedef int s32;
typedef short s16;

struct VEntry_0038A1E8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct Self_0038A1E8 {
    char pad0[0x64];
    char *p64;
    char pad1[0x4];
    void *p6c;
};

static inline s32 vcall_0038A1E8(Self_0038A1E8 *self) {
    VEntry_0038A1E8 *e = (VEntry_0038A1E8 *)(self->p64 + 0x310);
    return e->fn((char *)self + e->delta);
}

extern "C" s32 func_003C0FF0(void *arg0, s32 arg1);
extern "C" void func_003C1220(void *self, s32 i);

extern "C" void func_0038A1E8(Self_0038A1E8 *arg0) {
    void *s1 = arg0->p6c;
    if (func_003C0FF0(s1, vcall_0038A1E8(arg0)) == 0) {
        func_003C1220(s1, vcall_0038A1E8(arg0));
    }
}
