typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern "C" void AutomaticFader__update(void *self, f32 a);
extern "C" void AutomaticFader__oneshot(void *self, f32 a, f32 b, f32 c, f32 d);

struct RaceShiftPositionDisplay {
    char pad0[0x54];
    u8 unk54;
    u8 unk55;
    char pad56;
    u8 unk57;
};

extern "C" void RaceShiftPositionDisplay__update(RaceShiftPositionDisplay *arg0, f32 fparg0) {
    if (arg0->unk57 != 0) {
        if (arg0->unk54 != arg0->unk55) {
            arg0->unk55 = arg0->unk54;
            AutomaticFader__oneshot((char *)arg0 + 0x38, 0.0f, 0.0f, 0.0f, 0x1.333332p-3f);
        }
    }
    AutomaticFader__update((char *)arg0 + 0x38, fparg0);
}
