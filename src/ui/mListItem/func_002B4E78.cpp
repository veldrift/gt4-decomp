typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_003285A8(void *p);
extern "C" void func_0025C2D8(void *arg0, void *arg1);

struct VE2E {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

static inline void vcall2(char *o, s32 off, s32 a1) {
    VE2E *e = (VE2E *)(*(char **)(o + 4) + off);
    e->fn(o + e->delta, a1);
}

extern "C" void func_002B4E78(void *arg0, void *arg1, void *arg2) {
    char *self = (char *)arg0;
    char *obj = (char *)arg2;

    func_003285A8(arg2);
    vcall2(self, 0x2F8, (s32)arg2);
    func_0025C2D8(arg2, arg0);
    if (arg1 != 0) {
        vcall2(obj, 0x2B0, *(s32 *)((char *)arg1 + 0x10));
        vcall2(obj, 0x2C0, *(s32 *)((char *)arg1 + 0x10));
        vcall2(obj, 0x2D0, (s32)arg1);
    }
}
