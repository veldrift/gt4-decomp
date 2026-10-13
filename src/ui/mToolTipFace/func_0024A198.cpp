typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct S0024A198 {
    char pad0[0x118];
    u8 f118;
    char pad1[0x2F];
    f32 f148;
    f32 f14C;
};

struct S00490640;
extern "C" f32 func_00490640(struct S00490640 *arg0);
extern s32 D_00624978;
extern s32 D_00624980;

extern "C" void func_0024A198(struct S0024A198 *self) {
    switch (D_00624978) {
    case 0:
        self->f14C = 10.0f;
        break;
    case 10:
        self->f14C = 5.0f;
        break;
    case 8:
        self->f14C = 6.0f;
        break;
    default:
        self->f14C = 12.5f;
        break;
    }
    f32 r = func_00490640((struct S00490640 *)D_00624980);
    self->f148 = r;
    if (r <= 0.0f)
        self->f148 = 8.0f;
    self->f118 = 0;
}
