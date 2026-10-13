struct func_0038F240_sub {
    char pad0[0x38];
    float f38;
    char pad3C[0xA60 - 0x3C];
    float a60;
    float a64;
    float a68;
    float a6C;
};

struct func_0038F240_self {
    char pad0[0x23C];
    func_0038F240_sub *sub;
    float f240;
    float f244;
};

extern "C" float func_003983E0(void *, float, float);
extern "C" void func_004523E8(float, float, float, float);
extern "C" void func_00452408(float);

extern "C" void func_0038F240(func_0038F240_self *self)
{
    float t = func_003983E0(self->sub, self->f240, self->f244);
    func_0038F240_sub *v = self->sub;
    float inv = 1.0f / v->f38;
    func_004523E8(v->a60 * inv, v->a64 * inv, v->a68 * inv, v->a6C);
    func_00452408(t);
}
