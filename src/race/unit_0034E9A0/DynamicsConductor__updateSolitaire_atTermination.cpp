typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;

struct VEntry_240 {
    s16 delta;
    s16 index;
    char *(*fn)(char *, s32);
};

extern "C" s32 DynamicsConductor__GetNumberOfPylonsToBeTouched(char *arg0);
extern "C" char *func_0034C190(char *arg0, s32 arg1);
extern "C" u32 func_0035E3F0(char *arg0);

extern "C" s32 DynamicsConductor__updateSolitaire_atTermination(char *arg0) {
    char *s0 = *(char **)arg0;
    char *s2;
    s32 one;

    if (*(s32 *)(s0 + 0xDC) != 0) return 0;
    if (*(u8 *)(arg0 + 0xCBDC) != 0) return 0;
    if (*(s32 *)(s0 + 0xE0) != 0) return 0;

    s2 = s0 + 0x88;
    if (DynamicsConductor__GetNumberOfPylonsToBeTouched(arg0) > 0) return 0;

    {
        char *a2 = *(char **)(s0 + 0x84);
        VEntry_240 *e;
        char *r;
        one = 1;
        e = (VEntry_240 *)(*(char **)(a2 + 0x64) + 0x240);
        r = e->fn(a2 + e->delta, 0x100);
        if (*(s32 *)(r + 0x114) != 0) {
            if (*(s32 *)(s2 + 0x10) != 0) {
                *(s32 *)(s2 + 0x10) = 0;
            }
            return 0;
        }
    }

    if (func_0035E3F0(func_0034C190(arg0, 0)) == 0x157529FF) return 0;

    if (*(s32 *)(arg0 + 0xF8A0) != one) {
        if (*(s8 *)(func_0034C190(arg0, 1) + 0x56A) == 0) {
            u32 t1 = func_0035E3F0(func_0034C190(arg0, 0));
            u32 t2 = func_0035E3F0(func_0034C190(arg0, 1));
            if (!(t1 < t2)) return 0;
        }
    }

    *(s32 *)(s2 + 0xC) = 1;
    return 1;
}
