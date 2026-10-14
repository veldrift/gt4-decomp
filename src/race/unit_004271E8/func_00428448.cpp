typedef int s32;
typedef float f32;

struct Buf { char pad[0x30]; };

extern "C" f32 func_0042D430(void *a0, s32 a1, s32 a2);
extern "C" f32 func_0042A4A8(void *a0, s32 a1, s32 a2);
extern "C" void func_0042CEA8(void *a0, s32 a1);
extern "C" void func_0042C300(void *a0, s32 a1, void *a2, f32 f12);
extern "C" void func_0042C348(void *a0, s32 a1, void *a2, f32 f12, f32 f13);
extern "C" void func_0042CF10(void *a0, s32 a1);

extern "C" void func_00428448(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *out, f32 u12, f32 f13) {
    struct Buf sp;
    char *v = *(char **)(arg0 + 4);
    if (v != 0) {
        s32 s1;
        s32 s2;
        if (arg2 >= 0) {
            s1 = arg2;
            s2 = 1;
        } else {
            if (arg3 < 0) {
                return;
            }
            s1 = arg3;
            s2 = 0;
        }
        char *s0 = *(char **)(v + 0x10) + (arg1 << 4);
        f32 r;
        if (s2 != 0) {
            r = func_0042D430(*(char **)(s0 + 4) + (s1 << 5), arg2, arg3);
        } else {
            r = func_0042A4A8(*(char **)(s0 + 8) + (s1 << 5), arg2, arg3);
        }
        if (out != 0) {
            *out = r;
        }
        func_0042CEA8(&sp, arg4);
        if (s2 != 0) {
            func_0042C300(s0, s1, &sp, r);
        } else {
            func_0042C348(s0, s1, &sp, r, f13);
        }
        func_0042CF10(&sp, 2);
    }
}
