typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern "C" f32 func_0034C230(char *arg0);
extern "C" f32 func_0034C780(char *arg0, s32 arg1);

extern "C" s32 func_0035AE58(char *arg0) {
    s32 r = 0;
    char *s1 = arg0 + 0x104;
    char *s0 = *(char **)(arg0 + 0x4);
    u32 k = (u32)((*(u8 *)(s1 + 0x467) + 0xFE) & 0xFF);
    if (!(k < 3)) {
        return r;
    }
    f32 t = func_0034C230(s0);
    f32 f20 = *(f32 *)(s1 + 0x4A4);
    if (f20 < t * 0.5f) {
        f20 += t;
    }
    if (f20 < func_0034C780(s0, 1)) {
        return r;
    }
    if (func_0034C780(s0, -1) < f20) {
        return 0;
    }
    return 1;
}
