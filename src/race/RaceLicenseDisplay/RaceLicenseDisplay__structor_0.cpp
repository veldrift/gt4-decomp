extern "C" int RaceDisplay__structor_0(void *);
extern "C" void RaceTimeDisplay__structor_0(void *);
extern "C" void *RaceTexturePanel__structor_0(void *);
extern "C" void func_003A9758(void *);
extern "C" void RaceRichCountDisplay__structor_0(void *);
extern "C" void RaceValueDisplay__structor_0(void *);
extern "C" char RaceLicenseDisplay__vtable[];
extern "C" void *RaceLicenseDisplay__structor_0(char *self) {
    RaceDisplay__structor_0(self);
    *(void **)self = RaceLicenseDisplay__vtable;
    char *p = self + 0x3F30;
    for (int i = 2; i != -1; i--) {
        RaceTimeDisplay__structor_0(p);
        p += 0x70;
    }
    p = self + 0x4080;
    for (int i = 2; i != -1; i--) {
        RaceValueDisplay__structor_0(p);
        p += 0x94;
    }
    p = self + 0x423C;
    for (int i = 4; i != -1; i--) {
        func_003A9758(p);
        p += 0x1C;
    }
    RaceRichCountDisplay__structor_0(self + 0x42C8);
    return RaceTexturePanel__structor_0(self + 0x4360);
}
