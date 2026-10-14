extern "C" int func_004971A0(int first, int a, int b);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004A6498(int, int, int, int, int, int, int, int);
struct S { int f0; int f4; int f8; };
extern "C" void func_00497778(S *self, int a1, int a2, float fa) {
    float t = fa * (float)(a1 * a2);
    t = t * 0.25f;
    func_004971A0(self->f0, 0x40, self->f4);
    int s0 = self->f8;
    int lo = s0 & 0x3F;
    s0 = (s0 < 0) ? s0 + 0x3F : s0;
    int hi = s0 >> 6;
    func_004A1638(6);
    func_004A2808(0x88, 0.0f);
    func_004AA1D8(t, t, t, 1.0f);
    return func_004A6498(lo, hi, lo + 1, hi + 1, 0, 0, 0, 0);
}
