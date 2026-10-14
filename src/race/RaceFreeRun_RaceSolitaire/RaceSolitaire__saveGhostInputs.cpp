/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef long long s64;

struct Big { s64 b[0x2F]; };
struct Raw32 { char b[0x20]; };
struct N4 { char pad[0x3440]; s32 unk3440; };
struct N3 { s32 unk0; N4 *unk4; };
struct N2 { char pad[8]; N3 *unk8; };
struct N1 { char pad[0x60]; N2 *unk60; };

struct SrcAll {
    char pad0[0x6C];
    N1 *unk6C;
    char pad70[0xE920 - 0x70];
    char mgr[0xEDC0 - 0xE920];
    Big big;
    Raw32 raw;
    u8 f0; char p0[3];
    u8 f1; char p1[3];
    u8 f2; char p2[3];
    u8 f3; char p3[3];
    u8 f4; char p4[3];
    u8 f5; char p5[3];
};
struct DstAll {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x960 - 0x10];
    Big big;
    char pad_ad8[0xAD8 - 0x960 - 0x178];
    Raw32 raw;
    char padaf8[8];
    u8 g0, g1, g2, g3, g4, g5;
    char padB6[0x1AA0 - 0xB06];
    s32 unk1AA0;
};

extern "C" void AutomobileControlRecord__Manager__save(void *, void *, s32);

extern "C" void RaceSolitaire__saveGhostInputs(SrcAll *self, DstAll *out) {
    out->unkC = self->unk6C->unk60->unk8->unk4->unk3440;
    out->unk1AA0 = 1;
    out->big = self->big;
    out->raw = self->raw;
    out->g0 = self->f0;
    out->g1 = self->f1;
    out->g2 = self->f2;
    out->g3 = self->f3;
    out->g4 = self->f4;
    out->g5 = self->f5;
    AutomobileControlRecord__Manager__save(self->pad70 + (0xE920 - 0x70), out, 1);
}
