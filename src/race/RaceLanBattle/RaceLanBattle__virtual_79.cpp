typedef short s16;
typedef int s32;
typedef float f32;

extern "C" void RacePS2Base__raceEnd(struct RacePS2Base *arg0);

struct RacePS2Base {
    char pad0[0xCE0];
    s32 unkCE0;
    char pad1[0xE468 - 0xCE4];
    s32 unkE468;
    char pad2[0xF370 - 0xE46C];
    s32 unkF370;
};

extern "C" void RaceLanBattle__virtual_79(struct RacePS2Base *arg0) {
    struct RacePS2Base *self = arg0;
    if (self->unkE468 == 0) {
        s32 flags = self->unkF370 | 0x20;
        s32 field = (self->unkCE0 << 6) & 0x3C0;
        self->unkF370 = flags | field;
        return;
    }
    RacePS2Base__raceEnd(self);
}
