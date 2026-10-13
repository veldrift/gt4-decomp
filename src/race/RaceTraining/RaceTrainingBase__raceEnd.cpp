typedef short s16;
typedef int s32;
typedef float f32;

extern "C" void func_0033CCF0(struct RaceTrainingBase *arg0);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a1, f32 f12, f32 f13);
};

struct RaceTrainingBase {
    char pad0[0x64];
    void *unk64;
    char pad1[0xCD0 - 0x68];
    s32 unkCD0;
    char pad2[0xCE0 - 0xCD4];
    s32 unkCE0;
};

struct RaceTrainingBase__raceEnd_arg0 {
    char pad0[0x125F8];
    s32 unk125F8;
};

extern "C" void func_003ED188(struct RaceTrainingBase *arg0) {
    if ((((struct RaceTrainingBase__raceEnd_arg0 *)arg0)->unk125F8 != 0 || arg0->unkCD0 != 0) && arg0->unkCE0 == 0) {
        VEntry *e = (VEntry *)((char *)arg0->unk64 + 0x2B8);
        e->fn((char *)arg0 + e->delta, 1, 0.0f, 0.0f);
        return;
    }
    func_0033CCF0(arg0);
}
