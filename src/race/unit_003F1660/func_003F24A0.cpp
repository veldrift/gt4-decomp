typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Ent {
    u8 kind;
    char pad1[0x13];
    f32 f14;
    f32 f18;
    f32 f1C;
};

extern char D_00622268[];
extern u8 D_00620288[];

extern "C" f32 func_003F24A0(char *arg0, s32 arg1) {
    f32 r = 0.0f;
    char *q = *(char **)(arg0 + 0x10);
    Ent *p = (Ent *)(D_00622268 + ((*(u8 *)(q + 0x1076)) << 5));
    if (p->kind == 2) {
        f32 f0 = *(f32 *)(arg0 + 0x640);
        if (p->f1C <= f0) {
            r = p->f14;
        } else {
            f32 f2 = p->f18;
            if (f2 < f0) {
                r = (p->f14 * (f0 - f2)) / (p->f1C - f2);
            }
        }
    } else if (p->kind == 3) {
        char *e = arg0 + 0xEC * arg1;
        u8 idx = *(u8 *)(e + 0x1ED);
        if (D_00620288[idx] == 0) {
            r = p->f14;
        }
    }
    return r;
}
