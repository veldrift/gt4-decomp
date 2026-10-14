/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct S2C5880 {
    char p0[8];
    s32 w8;
    char p1[0x10];
    void *w1C;
    char p2[0x38];
    f32 f58;
    f32 f5C;
    f32 f60;
    f32 f64;
};

extern "C" void func_00247060(void *arg0, s32 arg1, s32 arg2, f32 f12, f32 f13, f32 f14, f32 f15);

extern "C" void func_002C5880(void *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    struct S2C5880 *s = (struct S2C5880 *)arg0;
    s32 t;
    char *p;
    if (s->w8 != 0) {
        p = (char *)s->w1C + 0xA0;
        t = 4;
        switch (arg2) {
        case 0:
            t = 3;
            break;
        case 1:
            t = 7;
            break;
        case 2:
            t = 5;
            break;
        case 3:
            t = 1;
            break;
        }
        func_00247060(p, arg1, t, fparg0 + s->f58, fparg1 + s->f5C, s->f60, s->f64);
    }
}
