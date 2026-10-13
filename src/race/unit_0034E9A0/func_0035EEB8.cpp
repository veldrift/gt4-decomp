typedef int s32;
typedef float f32;

extern char D_006208B8[];

extern "C" void func_0035EEB8(char *arg0, char *arg1, f32 *arg2, f32 *arg3) {
    s32 base = (s32)D_006208B8;
    s32 i = 0;

    do {
        s32 off = i << 2;
        f32 *pa = (f32 *)(arg0 + off);
        f32 *pb = (f32 *)(arg1 + off);
        f32 d = *(f32 *)(off + base);
        f32 a = *pa;
        f32 b = *pb;
        f32 nd = -d;
        f32 sum = a + b;

        if (sum < nd) {
            f32 na = a;
            f32 nb = nd - a;
            if (b * nb < 0.0f) {
                na = nd;
                nb = 0.0f;
            }
            *pa = na;
            *pb = nb;
            if (*arg2 < 0.0f) {
                *arg2 = 0.0f;
            }
            if (*arg3 < 0.0f) {
                *arg3 = 0.0f;
            }
        } else if (d < sum) {
            f32 na = a;
            f32 nb = d - a;
            if (b * nb < 0.0f) {
                na = d;
                nb = 0.0f;
            }
            *pa = na;
            *pb = nb;
            if (0.0f < *arg2) {
                *arg2 = 0.0f;
            }
            if (0.0f < *arg3) {
                *arg3 = 0.0f;
            }
        }

        i++;
        arg3++;
        arg2++;
    } while (i < 6);
}
