/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
typedef float f32;

struct Self {
    char pad0[0xC];
    f32 unkC;
    s32 unk10;
    char pad14[0x1F - 0x14];
    s8 unk1F;
    char pad20[2];
    s8 unk22;
    char pad23[0x2C - 0x23];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    char pad3C[0x22C - 0x3C];
    f32 unk22C;
    char pad230[0x24C - 0x230];
    s32 unk24C;
    s32 unk250;
};

extern "C" void func_001056A0(s32 arg0);
extern "C" void RaceDigitalSpeedmeter__render_main(void *) throw();
extern "C" void RaceGasMileageDisplay__render_main(void *) throw();
extern "C" void RaceGasConsumptionDisplay__render_main(void *) throw();
extern "C" void RacePriusPanel__init_texset(void *) throw();
extern "C" void RacePriusHybridDisplay__render_main(void *);
extern "C" void func_003AEF18(s32 t, f32 x, f32 y, s32 xf, s32 yf);
extern "C" s32 RaceDisplayUtil__getScaledColor(s32 c, f32 a, f32 b);
extern "C" void func_004AA168(s32);
extern "C" void func_004AA1D8(f32 r, f32 g, f32 b, f32 a);

extern "C" void RacePriusPanel__render_main(char *self, s32 arg1) {
    Self *s = (Self *)self;
    char *s1 = self + 0x150;
    char *s2 = self + 0x74;
    char *s0;
    char *p3;
    s0 = self + 0xE0;
    f32 f;
    func_001056A0(arg1);
    RacePriusPanel__init_texset(self);
    func_004AA1D8(1.0f, 1.0f, 1.0f, s->unkC);
    func_003AEF18(s->unk10, s->unk2C, s->unk30, 0, 0);
    p3 = self + 0x3C;
    *(f32 *)(p3 + 0xC) = s->unkC;
    *(f32 *)(s2 + 0xC) = s->unkC;
    *(f32 *)(s0 + 0xC) = s->unkC;
    *(f32 *)(s1 + 0xC) = s->unkC;
    RaceDigitalSpeedmeter__render_main(p3);
    RaceGasMileageDisplay__render_main(s2);
    RaceGasConsumptionDisplay__render_main(s0);
    RacePriusHybridDisplay__render_main(s1);
    if (s->unk1F == 3) {
        f = s->unk22C;
    } else {
        f = (f32)s->unk1F * 0.5f;
    }
    func_004AA168(RaceDisplayUtil__getScaledColor((s32)0x800099FF, f, s->unkC));
    func_003AEF18(s->unk24C, s->unk34, s->unk38, 1, 1);
    f = 1.0f;
    if (s->unk22 == 0) {
        f = 0.0f;
    }
    func_004AA168(RaceDisplayUtil__getScaledColor((s32)0x800000C8, f, s->unkC));
    func_003AEF18(s->unk250, s->unk2C, s->unk38, 0, 1);
}
