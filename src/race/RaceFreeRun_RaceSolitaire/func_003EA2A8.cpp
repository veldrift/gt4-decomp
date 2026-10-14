/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;

struct Big { s64 b[0x2F]; };
struct Raw32 { char b[0x20]; };

struct Dst {
    char pad0[0x20];
    Big big;
    char pad1[0x3448 - 0x20 - 0x178];
    s32 f3448, f344C, f3450, f3454, f3458, f345C;
    char pad2[0x3468 - 0x3460];
    Raw32 raw;
};
struct N2 { char pad[8]; Dst **unk8; };
struct N1 { char pad[0x60]; N2 *unk60; };

struct Src {
    char pad0[0x6C];
    N1 *unk6C;
    char pad70[0xEC10 - 0x70];
    Big big;
    Raw32 raw;
    s32 fa8, faC, fb0, fb4, fb8, fbc;
};

extern "C" void func_003EA2A8(Src *self) {
    Dst *d = *self->unk6C->unk60->unk8;
    d->big = self->big;
    d->raw = self->raw;
    d->f3448 = self->fa8 != 0;
    d->f344C = self->faC;
    d->f3450 = self->fb0 != 0;
    d->f3454 = self->fb4 != 0;
    d->f3458 = self->fb8 != 0;
    d->f345C = self->fbc;
}
