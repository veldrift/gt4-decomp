/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;

struct Fx {
    float f0;
    float f4;
};
struct Obj {
    char pad0[0x1B4];
    int unk1B4;
    char pad1B8[0x238 - 0x1B8];
    Fx fx;
    char pad240[0x260 - 0x240];
    float f260;
    char b264;
};

extern "C" void func_0036F948(Fx *, float, float, float, float) throw();
extern "C" void func_0036F968(Fx *, float) throw();
extern "C" void func_0036F970(Fx *, float) throw();
extern "C" void func_0036F978(Fx *, float) throw();
extern "C" float func_00578598(int);

extern "C" void func_00379FA8(Obj *self, int flag, float fp) {
    Fx *fx = &self->fx;
    int s = self->unk1B4;
    func_0036F948(fx, 0x1.999998p-4f, 0x1.333332p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(fx, 0.0f);
    func_0036F970(fx, 0.0f);
    func_0036F978(fx, 0.5f);
    func_0036F948(fx, 0x1.999998p-4f, func_00578598(s) * 0x1.333332p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(fx, func_00578598(s) * 40.0f - 20.0f);
    func_0036F970(fx, func_00578598(s) * 40.0f - 20.0f);
    if (flag != 0) fx->f4 = fx->f0;
    func_0036F978(fx, func_00578598(s) * 0.5f + 0x1.999998p-3f);
    self->f260 = fp;
    *(u64 *)((char *)self + 0x260) = (*(u64 *)((char *)self + 0x260) & 0xFFFFFF00FFFFFFFFull) | 0x100000000ull;
}
