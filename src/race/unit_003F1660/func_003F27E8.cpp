typedef float f32;
typedef int s32;
typedef unsigned char u8;

struct func_003F2798_p;

extern "C" f32 func_003F2798(struct func_003F2798_p *p, f32 x);

extern "C" void func_003F27E8(char *arg0) {
    char *a2 = *(char **)(arg0 + 0x10);
    s32 a1 = *(u8 *)(a2 + 0x1077);
    char *s0 = arg0 + 0x104;

    *(s32 *)(s0 + 0x594) = 0;
    *(s32 *)(s0 + 0x598) = 0;
    *(u8 *)(s0 + 0x592) = 0;
    *(u8 *)(s0 + 0x593) = 0;

    switch (a1) {
    case 1:
        if (*(f32 *)(a2 + 0x107C) <= *(f32 *)(s0 + 0x53C)) {
            f32 v = 1.0f;
            *(u8 *)(s0 + 0x592) = (u8)a1;
            *(f32 *)(s0 + 0x594) = v;
        }
        break;
    case 2: {
        f32 r = func_003F2798((struct func_003F2798_p *)arg0, *(f32 *)(s0 + 0x53C));
        *(f32 *)(s0 + 0x594) = r;
        break;
    }
    case 6:
        if (*(f32 *)(a2 + 0x107C) <= *(f32 *)(s0 + 0x53C)) {
            f32 v = 0x1.3B13B0p-3f;
            *(u8 *)(s0 + 0x592) = 1;
            *(f32 *)(s0 + 0x594) = v;
        }
        break;
    }
}
