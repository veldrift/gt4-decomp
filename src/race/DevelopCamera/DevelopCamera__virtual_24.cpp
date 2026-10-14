typedef int s32;
struct Blk { long w[8]; } __attribute__((aligned(8)));
struct G { float f0; char p4[0x10]; float f14; char p18[0x28]; };
extern G D_00620FC8;

extern "C" void DevelopCamera__virtual_24(char *arg0, float fa, float fb) {
    Blk *dst = (Blk *)(arg0 + 0x9C0);
    if (fa < 1.0f) {
        D_00620FC8.f0 = 1.0f;
        D_00620FC8.f14 = fa;
    } else {
        D_00620FC8.f14 = 1.0f;
        D_00620FC8.f0 = 1.0f / fa;
    }
    *dst = *(Blk *)&D_00620FC8;
    *(float *)((char *)dst + 0x40) = fb;
}
