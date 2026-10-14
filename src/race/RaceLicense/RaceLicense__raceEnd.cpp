typedef short s16;
typedef int s32;
typedef float f32;

extern "C" void RacePS2Base__raceEnd(void *self, s32 a);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, f32, f32);
};

struct RaceLicense {
    char pad0[0x64];
    void *unk64;
    char pad1[0xCD0 - 0x68];
    s32 unkCD0;
    s32 unkCD4;
    s32 unkCD8;
    s32 unkCDC;
    s32 unkCE0;
};

struct RaceLicense_24EE0 {
    char pad0[0x24EE0];
    s32 unk24EE0;
};

extern "C" void RaceLicense__raceEnd(void *arg0, s32 arg1) {
    struct RaceLicense *self = (struct RaceLicense *)arg0;
    s32 var_a1 = arg1;
    if ((((struct RaceLicense_24EE0 *)arg0)->unk24EE0 != 0) || (self->unkCD0 != 0)) {
        var_a1 = 1;
        if (self->unkCE0 == 0) {
            VEntry *e = (VEntry *)((char *)self->unk64 + 0x2B8);
            f32 z = 0.0f;
            e->fn((char *)self + e->delta, 1, z, z);
            return;
        }
    }
    RacePS2Base__raceEnd(arg0, var_a1);
}
