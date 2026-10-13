typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct VE343C20 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" s32 func_0034C158(s32 x, u32 i);
extern "C" f32 func_0034C230(void *arg0);
extern "C" u32 func_00358440(void *arg0);

extern "C" s32 func_00343C20(void *arg0) {
    char *self = (char *)arg0;
    char *d = self + 0x104;
    char *o = *(char **)(self + 4);
    s32 one = 1;
    s32 two = 2;
    s32 v0 = 0;

    if (*(u8 *)(d + 0x4B0) != 0) {
        return v0;
    }
    s32 t = func_0034C158((s32)o, func_00358440(o));
    v0 = 1;
    if (t != 0) {
        return v0;
    }
    VE343C20 *e = (VE343C20 *)(*(char **)(o + 0x10140) + 0x128);
    s32 s0 = e->fn(o + e->delta);
    if (s0 == 0) {
        return 0;
    }
    if (*(s16 *)(d + 0x4AC) < s0) {
        return 0;
    }
    f32 h = func_0034C230(o) * 0.5f;
    if (*(f32 *)(d + 0x4A4) < h) {
        s0 += 1;
    }
    s32 r = (*(s16 *)(d + 0x4AC) < s0) ? two : one;
    return r;
}
