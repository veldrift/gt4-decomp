typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry_1C0 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj_1C0 {
    char pad0[4];
    VEntry_1C0 *vtbl;
};

static inline void vcall_1C0(char *o, void *a) {
    VEntry_1C0 *e = (VEntry_1C0 *)((char *)((VObj_1C0 *)o)->vtbl + 0x1C0);
    e->fn(o + e->delta, a);
}

extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_00312318(void *arg0, int arg1);

extern "C" void MRenderContext__unloadGpb(void *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    char *s1;

    func_0022AD20(buf0, arg1);
    s1 = *(char **)((char *)buf0[0] + 0x10);
    func_0022ACC8(buf0, 2);
    func_00312370(buf0, arg3);
    vcall_1C0(s1, func_00314920((u8 *)buf0[0]));
    func_00312318(buf0, 2);
}
