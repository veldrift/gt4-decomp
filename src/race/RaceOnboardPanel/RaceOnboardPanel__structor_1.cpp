/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Bf { int v : 8; };

extern char RaceOnboardPanel__vtable[];

extern "C" void RaceDigitalSpeedmeter__structor_1(void *p) throw();
extern "C" void RaceOdometer__structor_1(void *p) throw();
extern "C" void func_003A4248(void *p, s32 n) throw();
extern "C" void RaceTexturePanel__structor_0(void *p) throw();
extern "C" void RaceTireWearDisplay__structor_1(void *p) throw();
extern "C" void RaceIndicator__structor_1(void *p) throw();
extern "C" void RaceShiftPositionDisplay__structor_1(void *p) throw();
extern "C" void RaceSuggestedGearDisplay__structor_1(void *p) throw();
extern "C" void RaceShiftTimingLampDisplay__structor_1(void *p) throw();
extern "C" int RacePanel__structor_1(void *p) throw();
extern "C" void RaceSideGravityMeter__structor_1(void *p);
extern "C" void RaceOnboardSpeedmeter__structor_0(void *p);
extern "C" void RaceOnboardTachometer__structor_0(void *p);
extern "C" void RaceBoostmeter__structor_0(void *p);

static inline void show(char *p, unsigned char v) { *(s32 *)p = (*(s32 *)p & ~0xFF) | v; }

extern "C" int RaceOnboardPanel__structor_1(char *a) {
    char *s1 = a + 0xA78;
    char *s2 = a + 0xC24;
    char *s3 = a + 0x9C0;
    char *s4 = a + 0x9E8;
    RacePanel__structor_1(a);
    *(void **)(a + 0x14) = RaceOnboardPanel__vtable;
    RaceTexturePanel__structor_0(a + 0x50);
    RaceOnboardSpeedmeter__structor_0(a + 0x6C);
    RaceOnboardTachometer__structor_0(a + 0xC8);
    RaceBoostmeter__structor_0(a + 0x964);
    RaceOdometer__structor_1(s3);
    RaceDigitalSpeedmeter__structor_1(s4);
    RaceShiftPositionDisplay__structor_1(a + 0xA20);
    RaceSuggestedGearDisplay__structor_1(s1);
    RaceShiftTimingLampDisplay__structor_1(a + 0xAD0);
    RaceTireWearDisplay__structor_1(a + 0xB0C);
    RaceIndicator__structor_1(a + 0xB3C);
    RaceIndicator__structor_1(a + 0xB80);
    RaceIndicator__structor_1(a + 0xBC4);
    RaceTexturePanel__structor_0(a + 0xC08);
    RaceSideGravityMeter__structor_1(s2);
    *(s32 *)(a + 0x2C) = 0;
    *(s32 *)(a + 0x30) = 0;
    *(s32 *)(a + 0x34) = 0;
    *(s32 *)(a + 0x38) = 0;
    *(s16 *)(a + 0x3C) = 0;
    *(s32 *)(a + 0x40) = 0;
    *(s32 *)(a + 0x44) = 0;
    *(s32 *)(a + 0x48) = 0;
    *(s32 *)(a + 0x4C) = 0;
    *(s32 *)(s4 + 0x2C) = 0x80E3B896;
    func_003A4248(s3, 6);
    show(s1, 1);
    show(s2, 1);
}
